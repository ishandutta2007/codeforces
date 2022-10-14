#include <bits/stdc++.h>

using namespace std;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif
  cout.precision(15);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run();
}

const int N = 200000;
const int logN = 19;

int n;

vector<int> graph[N];

int binary_lift_lca[N][logN];
int time_in[N];
int time_out[N];
int current_time;
int height[N];
// Dfs to calculate all important things
// Also generate Euler's tour
void dfs_precalc_lca(int v, int ancestor = -1) {
  binary_lift_lca[v][0] = ancestor;

  height[v] = (ancestor != -1 ? height[ancestor] + 1 : 0);
  if (v < 0 || v >= N) {
    cerr << "Fuck!";
  }
  time_in[v] = current_time++;

  for (int i = 1; i < logN; i++) {
    if (binary_lift_lca[v][i - 1] == -1) {
      binary_lift_lca[v][i] = -1;
    } else {
      binary_lift_lca[v][i] = binary_lift_lca[binary_lift_lca[v][i - 1]][i - 1];
    }
  }

  for (auto to : graph[v]) {
    dfs_precalc_lca(to, v);
  }

  time_out[v] = current_time;
}

int lowest[N];
int dfs_precalc_lowest(int v) {
  for (auto to : graph[v]) {
    lowest[v] = min(lowest[v], dfs_precalc_lowest(to));
  }
  return lowest[v];
}

// Dfs to calculate lowest vertices we can get from current in 2 ** i turns
int binary_lift_way[N][logN];
void dfs_precalc_binary_lift_way(int v) {
  binary_lift_way[v][0] = lowest[v];
  for (int i = 1; i < logN; i++) {
    binary_lift_way[v][i] = binary_lift_way[binary_lift_way[v][i - 1]][i - 1];
  }
  for (auto to : graph[v]) {
    dfs_precalc_binary_lift_way(to);
  }
}

// Check if v is ancestor of u
bool isAncestor(int v, int u) {
  if (v == -1) {
    return true;
  }
  if (u == -1) {
    return false;
  }
  return time_in[v] <= time_in[u] && time_out[v] >= time_out[u];
}

int lca(int v, int u) {
  if (isAncestor(v, u)) {
    return v;
  }
  if (isAncestor(u, v)) {
    return u;
  }
  for (int i = logN - 1; i >= 0; i--) {
    if (!isAncestor(binary_lift_lca[v][i], u)) {
      v = binary_lift_lca[v][i];
    }
  }
  return binary_lift_lca[v][0];
}

// Check if it's possible to get from v to u using routes
bool reachable(int v, int u) {
  for (int i = logN - 1; i >= 0; i--) {
    if (!isAncestor(binary_lift_way[v][i], u)) {
      v = binary_lift_way[v][i];
    }
  }
  v = binary_lift_way[v][0];
  return isAncestor(v, u);
}

// We go up from v, using as little number of buses as possible, until we get to the vertex
// From which we can get to u in one turn
// Returns pair<int, int> --- penultimate vertex on the way and the number of buses we used
pair<int, int> penultimate(int v, int u) {
  int cnt = 0;
  for (int i = logN - 1; i >= 0; i--) {
    if (!isAncestor(binary_lift_way[v][i], u)) {
      cnt += (1 << i);
      v = binary_lift_way[v][i];
    }
  }
  return {v, cnt};
}

// Here is just classical fenwick we'll use in dfs_calculate_answer
int fenwick[N + 1];

int f(int a) {
  return a & (-a);
}

void fenwickAdd(int v, int val = 1) {
  v++; // Fenwick is 1 indexed, v is 0 indexed
  for (; v <= N; v += f(v)) {
    fenwick[v] += val;
  }
}

int fenwickGet(int r) {
  int ans = 0;
  for (; r > 0; r -= f(r)) {
    ans += fenwick[r];
  }
  return ans;
}

int fenwickGet(int l, int r) {
  return fenwickGet(r) - fenwickGet(l);
}
int answer[N];
vector<pair<int, int>> query_for_vertex[N];

int cnt_on_segment[N];

vector<int> way_end[N];

void dfs_calculate_answer(int v) {
  for (auto query : query_for_vertex[v]) {
    int u, id;
    tie(u, id) = query;
    cnt_on_segment[id] -= fenwickGet(time_in[u], time_out[u]);
  }

  for (auto end : way_end[v]) {
    fenwickAdd(time_in[end]);
  }

  for (auto to : graph[v]) {
    dfs_calculate_answer(to);
  }

  // The same thing as at the beginning
  for (auto query : query_for_vertex[v]) {
    int u, id;
    tie(u, id) = query;
    cnt_on_segment[id] += fenwickGet(time_in[u], time_out[u]);

    // That means that exists the route, connecting v and u
    if (cnt_on_segment[id] > 0) {
      answer[id]--; // So our assuming is incorrect and we should decrease answer
    }
  }
}

pair<int, int> way[N];

bool bad[N];

int run() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    --p;
    graph[p].push_back(i);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    way_end[v].push_back(u); // We will know where routes starting in this vertex end
    way_end[u].push_back(v); // We'll need it in dfs_calculate_answer
    way[i] = {v, u};
  }

  // Precalc lca, Euler's tour and heights
  dfs_precalc_lca(0);

  // For each vertex we store lowest possible vertex
  // In one turn
  // Initially it's just its height
  for (int i = 0; i < n; i++) {
    lowest[i] = i;
  }

  // Split way to vertical
  for (int i = 0; i < m; i++) {
    int v, u;
    tie(v, u) = way[i];
    int lca_ = lca(v, u);
    if (height[lowest[v]] > height[lca_] ) {
      lowest[v] = lca_;
    }
    if (height[lowest[u]] > height[lca_]) {
      lowest[u] = lca_;
    }
  }

  dfs_precalc_lowest(0);

  // Now we precalc binary lifts to answer queries
  dfs_precalc_binary_lift_way(0);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    int len_v, len_u;
    int lca_ = lca(v, u);

    if (!reachable(v, lca_) || !reachable(u, lca_)) { // It's impossible to get from vertex to lca
      bad[i] = true;
    }

    tie(v, len_v) = penultimate(v, lca_);
    tie(u, len_u) = penultimate(u, lca_);

    if (v != lca_ && u != lca_) { // Route isn't vertical
      query_for_vertex[v].push_back({u, i}); // Here we store query's second vertex and id
    }

    answer[i] = len_v + len_u;

    // We assume there is no direct route between v and u
    // Overwise we'll decrement it later
    if (v != lca_) {
      answer[i]++;
    }
    if (u != lca_) {
      answer[i]++;
    }
  }

  dfs_calculate_answer(0);

  for (int i = 0; i < q; i++) {
    cout << (bad[i] ? -1 : answer[i]) << '\n';
  }
}