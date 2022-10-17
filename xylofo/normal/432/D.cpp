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
    int len, link, cnt;
    map<char, int> nxt;
    bool term = false;
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

  // optional
  void calc_cnt(){
    vector<vi> ls(st[last].len+1);
    rep(i,0,sz(st)) ls[st[i].len].push_back(i);
    for(int len = st[last].len; len; --len)
      for(auto i : ls[len])
        st[st[i].link].cnt += st[i].cnt;
    for(int p = last; p; p = st[p].link) st[p].term = true;
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s;
  cin>>s;
  SuffixAutomaton sa;
  for(char c:s) sa.extend(c);
  sa.calc_cnt();

  vector<pii> ans;
  int node = 0;
  rep(i,0,sz(s)){
    if(!sa.st[node].nxt.count(s[i])) break;
    node = sa.st[node].nxt[s[i]];
    if(sa.st[node].term)
      ans.emplace_back(i+1, sa.st[node].cnt);
  }
  cout << sz(ans) << endl;
  for(pii p:ans) cout << p.first << " " << p.second << "\n";
}