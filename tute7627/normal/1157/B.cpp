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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(10);
  for(i = 1; i <= 9; i++)
    cin >> a[i]; 
  for(i = 0; i < n; i++)
    if(a[s[i] - '0'] > s[i] - '0')
      break;
  if(i != n)
    for(; i < n; i++){
      if(a[s[i] - '0'] >= s[i] - '0')
        s[i] = a[s[i] - '0'] + '0';
      else 
        break;
    }
  

  cout << s << endl;

  return 0;
}