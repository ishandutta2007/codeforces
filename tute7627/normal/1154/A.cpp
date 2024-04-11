#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main(){
  ll i, j;
  vector<ll> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(ALL(a));
  cout << a[3] - a[2] spa a[3] - a[1] spa a[3] - a[0] << endl;

  return 0;
}