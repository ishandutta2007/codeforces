#include <bits/stdc++.h>
using namespace std;

constexpr int P[] = {1000033, 4000037, 1000033, 4000037};
constexpr int Q[] = {1000000007, 1000000007, 1000000009, 1000000009};

constexpr int Pow(int a, int b, int m)
{
  int ret = 1;
  a %= m;
  while (b)
  {
    if (b & 1) ret = ret * 1ll * a % m;
    b >>= 1;
    a = a * 1ll * a % m;
  }
  return ret;
}

int modpow[4][1000005];

constexpr int modinv[4] =
{
  Pow(P[0], Q[0] - 2, Q[0]),
  Pow(P[1], Q[1] - 2, Q[1]),
  Pow(P[2], Q[2] - 2, Q[2]),
  Pow(P[3], Q[3] - 2, Q[3]),
};

static_assert(P[0] * 1ll * modinv[0] % Q[0] == 1, "");
static_assert(P[1] * 1ll * modinv[1] % Q[1] == 1, "");
static_assert(P[2] * 1ll * modinv[2] % Q[2] == 1, "");
static_assert(P[3] * 1ll * modinv[3] % Q[3] == 1, "");

struct BipartiteMatching {
  int n, m;
  vector<vector<int>> graph;
  vector<int> matched, match, edgeview, level;
  vector<int> reached[2];
  BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1),
  match(n, -1) {}
  bool assignLevel() {
    bool reachable = false;
    level.assign(n, -1);
    reached[0].assign(n, 0);
    reached[1].assign(m, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (match[i] == -1) {
        level[i] = 0;
        reached[0][i] = 1;
        q.push(i);
      }
    }
    while (!q.empty()) {
      auto cur = q.front(); q.pop();
      for (auto adj : graph[cur]) {
        reached[1][adj] = 1;
        auto next = matched[adj];
        if (next == -1) {
          reachable = true;
        }
        else if (level[next] == -1) {
          level[next] = level[cur] + 1;
          reached[0][next] = 1;
          q.push(next);
        }
      }
    }
    return reachable;
  }
  int findpath(int nod) {
    for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
      int adj = graph[nod][i];
      int next = matched[adj];
      if (next >= 0 && level[next] != level[nod] + 1) continue;
      if (next == -1 || findpath(next)) {
        match[nod] = adj;
        matched[adj] = nod;
        return 1;
      }
    }
    return 0;
  }
  int solve() {
    int ans = 0;
    while (assignLevel()) {
      edgeview.assign(n, 0);
      for (int i = 0; i < n; i++)
        if (match[i] == -1)
          ans += findpath(i);
    }
    return ans;
  }
};

struct Hash
{
  array<int, 4> dat{};
  int len = 0;
  mutable int idx = 0;
  char ch = -1;

  bool operator==(const Hash &h) const
  {
    return memcmp(&dat[0], &h.dat[0], sizeof(dat)) == 0;
  }

  void push_back(char ch)
  {
    if (this->ch == -1) this->ch = ch;
    for (int i = 0; i < 4; i++)
    {
      dat[i] = (dat[i] + 1ll * ch * modpow[i][len]) % Q[i];
    }
    ++len;
  }

  void pop_front()
  {
    for (int i = 0; i < 4; i++)
    {
      dat[i] = (dat[i] + Q[i] - ch) * 1ll * modinv[i] % Q[i];
    }
    --len;
  }
};

struct hashfunc
{
  size_t operator()(const Hash &h) const
  {
    return h.dat[0] ^ h.dat[1] ^ h.dat[2] ^ h.dat[3];
  }
};

unordered_set<Hash, hashfunc> st[2];

int main()
{
  for (int i = 0; i < 4; i++)
  {
    modpow[i][0] = 1;
    for (int j = 1; j < 1000000; j++)
    {
      modpow[i][j] = modpow[i][j - 1] * 1ll * P[i] % Q[i];
    }
  }

  cin.sync_with_stdio(false);
  int T; cin >> T;
  while (T--)
  {
    st[0].clear();
    st[1].clear();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      string str;
      cin >> str;
      Hash h;

      for (char ch : str)
      {
        h.push_back(ch);
        st[h.len & 1].insert(h);
      }
    }

    {
      int idx1 = 0;
      for (auto &e : st[0]) e.idx = idx1++;

      idx1 = 0;
      for (auto &e : st[1]) e.idx = idx1++;
    }

    BipartiteMatching bm(st[0].size(), st[1].size());

    for (auto &e : st[0])
    {
      Hash nxt = e;
      nxt.pop_front();
      auto itr = st[1].find(nxt);
      if (itr == st[1].end()) continue;

      bm.graph[e.idx].push_back(itr->idx);
    }

    for (auto &e : st[1])
    {
      Hash nxt = e;
      nxt.pop_front();
      auto itr = st[0].find(nxt);
      if (itr == st[0].end()) continue;

      bm.graph[itr->idx].push_back(e.idx);
    }

    printf("%d\n", (int)(st[0].size() + st[1].size() - bm.solve()));
  }
}