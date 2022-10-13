#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  ll S = 0LL;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    S += a[i];
  }
  if(S%2) ++S; //check this
  ll ans = 1LL; // 0C
  ll temp = 0LL;
  for(int i=n-1;i>=2;i--) { //first C
    temp += a[i];
    if(temp * 2 < S) {
      ++ans;
    }
  }
  temp = 0LL;
  ordered_set even, odd;
  vector<ll> prefPar(n);
  for(int i=0;i<n;i++) {
    if(i==0) prefPar[0] = a[0];
    else if(i==1) prefPar[1] = a[1];
    else {
      prefPar[i]= a[i] + prefPar[i-2];
    }
    if(i%2==0) even.insert(prefPar[i]);
    else odd.insert(prefPar[i]);
  }
  even.erase(prefPar[0]);
  //first C at pos 1
  for(int r=1;r<n;r++) {
    temp += a[r];
    if(temp*2 >= S) break;
    //edge cases
    if(r==n-1) {
      ++ans;
      continue;
    }
    if(r == n-2) {
      ++ans;
      continue;
    }
    int ch = 0;
    //include a[n-1]
    //move 2 k>=0 times and account for overcount
    if(r%2==0) {
      ch += even.order_of_key(S/2-a[n-1]-temp+prefPar[r]);
    }
    else {
      ch += odd.order_of_key(S/2-a[n-1]-temp+prefPar[r]);
    }
    //overcount if a[n-1] included twice or a[n-2] is included
    if((n-1-r)%2==0 && (temp + prefPar[n-1] - prefPar[r] + a[n-1])*2 < S) --ch;
    if((n-2-r)%2==0 && (temp + prefPar[n-2] -  prefPar[r] + a[n-1])*2 < S) --ch;
    //don't include a[n-1]
    //move 2 k>=0 times
    if(r%2==0) ch += even.order_of_key(S/2+prefPar[r] - temp);
    else ch += odd.order_of_key(S/2 + prefPar[r] - temp);
    if((n-1-r)%2==0 && (temp + prefPar[n-1] - prefPar[r])*2 < S) --ch; //overcount if a[n-1] is included

    if(r%2==0) even.erase(prefPar[r]);
    else odd.erase(prefPar[r]);
    ans += ch;
  }
  //first C at pos 0
  temp = 0LL;
  even.clear();
  odd.clear();
  for(int i=0;i<n;i++) {
    if(i%2==0) even.insert(prefPar[i]);
    else odd.insert(prefPar[i]);
  }
  for(int r=0;r<n;r++) {
    temp += a[r];
    if(temp*2 >= S) break;
    //edge cases
    if(r==n-1) {
      ++ans;
      continue;
    }
    if(r == n-2) {
      ++ans;
      continue;
    }
    int ch = 0;
    //include a[n-1]
    //move 2 k>=0 times and account for overcount
    if(r%2==0) {
      ch += even.order_of_key(S/2-a[n-1]-temp+prefPar[r]);
    }
    else {
      ch += odd.order_of_key(S/2-a[n-1]-temp+prefPar[r]);
    }
    //overcount if a[n-1] included twice or a[n-2] is included
    if((n-1-r)%2==0 && (temp + prefPar[n-1] - prefPar[r] + a[n-1])*2 < S) --ch;
    if((n-2-r)%2==0 && (temp + prefPar[n-2] -  prefPar[r] + a[n-1])*2 < S) --ch;
    //don't include a[n-1]
    //move 2 k>=0 times
    if(r%2==0) ch += even.order_of_key(S/2+prefPar[r] - temp);
    else ch += odd.order_of_key(S/2 + prefPar[r] - temp);
    if((n-1-r)%2==0 && (temp + prefPar[n-1] - prefPar[r])*2 < S) --ch; //overcount if a[n-1] is included

    if(r%2==0) even.erase(prefPar[r]);
    else odd.erase(prefPar[r]);
    ans += ch;
  }
  ll MOD = 998244353;
  cout << (ans%MOD+MOD)%MOD << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
}