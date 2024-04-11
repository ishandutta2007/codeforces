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
    complex<int> cnt;
    map<char, int> nxt; // consider using array
  };
  int last = 0;
  vector<node> st = {node{0, -1, 0}};

  void extend(char c, int str) {
    int p = last;
    last = sz(st);
    st.push_back(node{st[p].len + 1, 0, {1-str, str}});
    for(; p >= 0 && !st[p].nxt.count(c); p = st[p].link)
      st[p].nxt[c] = last;

    if (p < 0) return;
    int q = st[p].nxt[c];
    st[last].link = q;
    if(st[p].len + 1 == st[q].len) return;
    int clone = sz(st);
    st.push_back(st[q]);
    st[clone].len = st[p].len + 1;
    st[clone].cnt = 0;
    for(; p >= 0 && st[p].nxt[c] == q; p = st[p].link)
      st[p].nxt[c] = clone;
    st[q].link = st[last].link = clone;
  }

  void calc_cnt(){
    vector<vi> ls(st[last].len+1);
    rep(i,0,sz(st)) ls[st[i].len].push_back(i);
    for(int len = st[last].len; len; --len)
      for(auto i : ls[len])
        st[st[i].link].cnt += st[i].cnt;
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s,t;
  cin>>s>>t;

  SuffixAutomaton sa;
  for(char c:s) sa.extend(c,0);
  sa.extend('$',0);
  for(char c:t) sa.extend(c,1);
  sa.extend('#',1);
  sa.calc_cnt();

  int best = 1e9;
  for(auto &node : sa.st) {
    if(norm(node.cnt) == 2 && node.link >= 0) {
      best = min(best, sa.st[node.link].len+1);
    }
  }
  if(best == 1e9) best = -1;
  cout << best << endl;
}