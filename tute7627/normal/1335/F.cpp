#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
typedef vector<vector<int>> UnWeightedGraph;
template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return (comp[k]);
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};

map<char, int> dh, dw;
UnWeightedGraph g;
vector<l_l> v;
int len;
bool can[1000000];
bool color[1000000];
void f(int now, int root, int l) {
    v.push_back({now, l});
    for(auto to : g[now]) {
        if(to == root) {
            len = l + 1;
            continue;
        }
        f(to, root, l + 1);
    }
}
void solve() {
    ll H, W;
    cin >> H >> W;
    g.clear();
    g.resize(H*W);
    for(int h = 0; h < H; h++) {
        string S;
        cin >> S;
        for(int w = 0; w < W; w++) {
            color[h*W+w] = (S[w] == '0');
        }
    }
    for(int h = 0; h < H; h++) {
        string S;
        cin >> S;
        for(int w = 0; w < W; w++) {
            int now = h * W + w;
            int toh = h + dh[S[w]];
            int tow = w + dw[S[w]];
            int to = toh * W + tow;
            g[to].push_back(now);
        }
    }
    StronglyConnectedComponents<UnWeightedGraph> SCC(g);
    UnWeightedGraph t;
    SCC.build(t);
    map<int, vector<int>> mp;
    ll N = H * W;
    for(int i = 0; i < N; i++) {
        mp[SCC[i]].push_back(i);
    }
    vector<int> root;
    for(auto tmp : mp) {
        if(tmp.second.size() <= 1) continue;
        root.push_back(tmp.second[0]);
    }
    /*
    for(auto tmp : root) cerr << tmp << " ";
    cerr << endl;
    */
    ll ans1 = 0;
    ll ans2 = 0;
    for(auto r : root) {
        v.clear();
        f(r, r, 0);
        ans1 += len;
        for(int i = 0; i < len; i++) can[i] = false;
        for(int i = 0; i < v.size(); i++) {
            v[i].second %= len;
            if(color[v[i].first]) can[v[i].second] = true;
        }
        for(int i = 0; i < len; i++) {
            if(can[i]) ans2++;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    dh['U'] = -1;
    dh['D'] = 1;
    dw['R'] = 1;
    dw['L'] = -1;
    while(T--) solve();
    return 0;
}