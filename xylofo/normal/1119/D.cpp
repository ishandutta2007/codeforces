#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(NULL);
  int n,q;
  cin>>n;
  vector<ll> s(n);
  rep(i,0,n) cin>>s[i];
  sort(all(s));
  map<ll,int> event;
  rep(i,1,n) {
    event[s[i]-s[i-1]]++;
  }
  cin>>q;
  vector<ll> qr(q);
  rep(i,0,q) {
    ll l, r;
    cin>>l>>r;
    qr[i] = r - l + 1;
    event[qr[i]] += 0;
  }
  map<ll, ll> ans;

  int cnt = n;
  ll lst = 0;
  ll acc = 0;
  for(auto [t, delta] : event) {
    acc += cnt * (t - lst);
    ans[t] = acc;
    cnt -= delta;
    lst = t;
  }
  rep(i,0,q) {
    cout << ans[qr[i]] << " ";
  }
  cout << endl;
  return 0;
}