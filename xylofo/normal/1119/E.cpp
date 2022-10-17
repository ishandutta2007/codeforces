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
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  ll ans = 0;
  ll debt = 0;
  for(int i = n-1; i >= 0; --i) {
    int k = a[i] / 2;
    a[i] -= k * 2;
    debt += k;
    if(a[i] > 0 && debt > 0) {
      ans++;
      debt--;
    }
  }
  ans += (debt * 2) / 3;
  cout << ans << endl;
  return 0;
}