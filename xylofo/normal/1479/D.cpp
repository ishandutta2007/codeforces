#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5+10;
const int B = 600;

int n;
int block[MAXN/B+10], use[MAXN], L[MAXN], R[MAXN], a[MAXN];

void add(int ind, int end) {
  int q = a[ind];
  if(use[q]) {
    --block[q/B];
    use[q] = 0;
  }
  else {
    ++block[q/B];
    use[q] = 1;
  }
}
void del(int ind, int end) { add(ind, end); }

int calc(int q) {
  int x = L[q], y = R[q]+1;

  while(x < y && x % B != 0) { // align x
    if(use[x]) return x;
    ++x;
  }
  while(x < y && block[x/B] == 0) {// find block
    x += B;
  }
  while(x < y) { // traverse block
    if(use[x]) return x;
    ++x;
  }

  return -1;
}

vi moTree(vector<array<int, 2>> Q, vector<vi>& ed, int root=0){
  int N = sz(ed), pos[2] = {}, blk = 600; // ~N/sqrt(Q)
  vi s(sz(Q)), res = s, I(N), L(N), R(N), in(N), par(N);
  add(0, 0), in[0] = 1;
  auto dfs = [&](int x, int p, int dep, auto& f) -> void {
    par[x] = p;
    L[x] = N;
    if (dep) I[x] = N++;
    for (int y : ed[x]) if (y != p) f(y, x, !dep, f);
    if (!dep) I[x] = N++;
    R[x] = N;
  };
  dfs(root, -1, 0, dfs);
#define K(x) pii(I[x[0]] / blk, I[x[1]] ^ -(I[x[0]] / blk & 1))
  rep(i,0,sz(Q)) {
    if(I[Q[i][0]] > I[Q[i][1]])
      swap(Q[i][0], Q[i][1]);
  }
  iota(all(s), 0);
  sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
  for (int qi : s) rep(end,0,2) {
    int &a = pos[end], b = Q[qi][end], i = 0;
#define step(c) { if (in[c]) { del(a, end); in[a] = 0; } \
  else { add(c, end); in[c] = 1; } a = c; }
    while (!(L[b] <= L[a] && R[a] <= R[b]))
      I[i++] = b, b = par[b];
    while (a != b) step(par[a]);
    while (i--) step(I[i]);
    if (end) res[qi] = calc(qi);
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  rep(i,0,n) cin>>a[i];
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  vector<array<int,2>> query(q);
  rep(i,0,q) {
    cin>>query[i][0]>>query[i][1]>>L[i]>>R[i];
    --query[i][0], --query[i][1];
  }

  auto ans = moTree(query, g);
  for(int x:ans) cout << x << "\n";
}