#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif


struct SuffixAutomaton {
  struct node {
    int len = 0, link = -1;
    map<char, int> nxt;
  };
  int last = 0;
  vector<node> st = {node{0, -1, {}}};

  void extend(char c) {
    int p = last;
    last = sz(st);
    st.emplace_back(node{st[p].len + 1, 0, {}});
    for(; p != -1 && !st[p].nxt.count(c); p = st[p].link)
      st[p].nxt[c] = last;

    if (p != -1) {
      int q = st[p].nxt[c];
      if(st[p].len + 1 == st[q].len) st[last].link = q;
      else {
        int clone = sz(st);
        st.emplace_back(st[q]);
        st[clone].len = st[p].len + 1;
        for(; p != -1 && st[p].nxt[c] == q; p = st[p].link)
          st[p].nxt[c] = clone;
        st[q].link = st[last].link = clone;
      }
    }
  }

  bool exists(const string &s, int pos, bool cheat, int node = 0) {
    debug(s.substr(pos), cheat, node);
    debug(st[node].nxt);
    if(pos == sz(s)) return !cheat;
    for(auto [ch, nd] : st[node].nxt) {
      if(ch == s[pos] && exists(s, pos+1, cheat, nd))
        return true;
      if(cheat && s[pos] != '#' && ch != '#' && ch != s[pos] && exists(s, pos+1, false, nd))
        return true;
    }
    return false;
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  SuffixAutomaton sa;
  sa.extend('#');
  string s;
  rep(i,0,n) {
    cin>>s;
    for(char c: s) sa.extend(c);
    sa.extend('#');
  }
  rep(i,0,m) {
    cin>>s;
    s = "#" + s + "#";
    debug(s);
    if(sa.exists(s, 0, true)) cout << "YES\n";
    else cout << "NO\n";
  }
}