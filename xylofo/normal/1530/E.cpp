#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve(int tc) {
  string s;
  cin >> s;
  sort(all(s));

  if(s[0] == s.back()) { // only one char
    cout << s << endl;
    return;
  }

  string ans;
  vi cnt(30);
  for(char c : s) ++cnt[c-'a'];

  int uq = -1;
  rep(i,0,sz(cnt)) if(cnt[i] == 1) { uq = i; break; }
  if(uq != -1) { // least unique char
    --cnt[uq];
    ans += 'a'+uq;
    rep(i,0,sz(cnt)) rep(_,0,cnt[i]) ans += 'a'+i;
    cout << ans << endl;
    return;
  }

  int a = -1, b = -1, c = -1;
  rep(i,0,sz(cnt)) if(cnt[i]) {
    if(a == -1) a = i;
    else if(b == -1) b = i;
    else if(c == -1) c = i;
  }
  assert(a != -1 && b != -1 && b != a);
  debug(a,b,c);

  if((cnt[a]-2)*2 <= (sz(s)-2)) { // aab..
    ans += 'a'+a; --cnt[a];
    ans += 'a'+a; --cnt[a];
  }
  else if(c != -1) { // aba...
    ans += 'a'+a; --cnt[a];
    ans += 'a'+b; --cnt[b];
  }
  else { // abb...bbbaaa..aa
    reverse(all(s));
    rotate(begin(s), end(s)-1, end(s));
    cout << s << endl;
    return;
  }

  rep(i,0,sz(s)-1) { // handle aab.. and aba.. cases
    rep(t,0,sz(cnt)) if(cnt[t]) {
      if(ans[0] == ans.back() && ans[1] == 'a'+t) continue;
      ans += 'a'+t; --cnt[t];
      break;
    }
  }
  assert(sz(ans) == sz(s));
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}