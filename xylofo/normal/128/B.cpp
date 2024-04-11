#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixAutomaton {
  struct node {
    int len, link;
    ll cnt;
    map<char, int> nxt; // consider using array
    ll d = -1;
  };
  int last = 0;
  vector<node> st = {node{0, -1, 0}};

  void extend(char c) {
    int p = last;
    last = sz(st);
    st.push_back(node{st[p].len + 1, 0, 1});
    for(; p >= 0 && !st[p].nxt.count(c); p = st[p].link)
      st[p].nxt[c] = last;

    if (p >= 0) {
      int q = st[p].nxt[c];
      if(st[p].len + 1 == st[q].len) st[last].link = q;
      else {
        int clone = sz(st);
        st.push_back(st[q]);
        st[clone].len = st[p].len + 1;
        st[clone].cnt = 0;
        for(; p >= 0 && st[p].nxt[c] == q; p = st[p].link)
          st[p].nxt[c] = clone;
        st[q].link = st[last].link = clone;
      }
    }
  }

  void calc_d(){
    function<ll(int)> dfs = [&](int x){
      if(st[x].d != -1) return st[x].d;
      st[x].d = st[x].cnt;
      for(auto [c, y] : st[x].nxt)
        st[x].d += dfs(y);
      return st[x].d;
    };
    dfs(0);
  }
  void calc_cnt(){
    vector<vi> ls(st[last].len+1);
    rep(i,0,sz(st)) ls[st[i].len].push_back(i);
    for(int len = st[last].len; len; --len)
      for(auto i : ls[len])
        st[st[i].link].cnt += st[i].cnt;
  }

  void findK(ll k, string &ans, int node = 0) {
    if(k < st[node].cnt) return;
    k -= st[node].cnt;
    for(auto [c, nd] : st[node].nxt) {
      if(k < st[nd].d) {
        ans += c;
        findK(k, ans, nd);
        return;
      }
      k -= st[nd].d;
    }
    ans = "No such line.";
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s;
  int n;
  cin>>s>>n;
  SuffixAutomaton sa;
  for(char c:s) sa.extend(c);
  sa.calc_cnt();
  sa.calc_d();

  string ans = "";
  sa.findK(n+sz(s)-1, ans);
  cout << ans << endl;
}