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
  i = 0;
  if(n % 10 == 0){
    i++;
    n++;
  }
  
  for(; n > 10;){
    if(n % 10 != 0){
      n++;
      i++;
    }
    else
      n /= 10;
  }
  cout << i + 9 << endl;

  return 0;
}