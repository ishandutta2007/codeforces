#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

vector<ll> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll x, s;
  cin >> x >> s;
  if(x%2 != s%2 || s < x){
    cout << -1 << endl;
    return 0;
  }
  s -= x;
  ll a = s>>1;
  ll b = s>>1;
  if((a&x) == 0){
    x |= a;
    a = 0;
  }

  A.push_back(x);
  A.push_back(a);
  A.push_back(b);
  int cnt = 0;
  for(ll i : A){
    if(i)
      cnt++;
  }
  cout << cnt << endl;
  for(ll i : A){
    if(i)
      cout << i << " ";
  }
  cout << endl;

  return 0;
}