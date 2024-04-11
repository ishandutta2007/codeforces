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
    map<char, int> nxt; // consider using array
    int first_pos = -1;
  };
  int last = 0;
  vector<node> st = {node{0, -1, 0}};

  void extend(char c) {
    int p = last;
    last = sz(st);
    st.push_back(node{st[p].len + 1, 0, 1});
    st.back().first_pos = st.back().len;
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
  vi pos(const string &s) {
    int x = 0, n = sz(s);
    vi res(n,st[last].len);
    rep(i,0,n) {
      if(!st[x].nxt.count(s[i])) break;
      x = st[x].nxt[s[i]];
      res[i] = st[x].first_pos;
    }
    return res;
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s;
  cin>>s;
  SuffixAutomaton sa, sr;
  rep(i,0,sz(s)) {
    sa.extend(s[i]);
    sr.extend(s[sz(s)-i-1]);
  }
  int n = sz(s), m, ans = 0;
  cin>>m;
  rep(i,0,m) {
    string s;
    cin>>s;
    vi ps = sa.pos(s);
    reverse(all(s));
    vi pr = sr.pos(s);
    bool good = false;
    rep(i,1,sz(s)) {
      int j = sz(s)-i;
      if(ps[i-1] + pr[j-1] <= n) good = true;
    }
    if(good) ++ans;
  }
  cout << ans << endl;
}