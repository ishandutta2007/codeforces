#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll X;
vector<ll> fct;
int fctsz;

void factor(ll A){
  fctsz = 0;
  fct.resize(30);
  for(int i=0; i<30; i++){
    fct[i] = 0;
  }
  for(ll i=2; A>0; i++){
    fct[A%i]++;
    A /= i;
    fctsz++;
  }
}

ll ch(ll k, ll n){
  if(k > n || k < 0 || n < 0)
    return 0;
  ll res = 1;
  for(ll i=0; i<k; i++){
    res *= n-i;
  }
  for(ll i=0; i<k; i++){
    res /= i+1;
  }
  return res;
}

ll pos(){
  ll res = 1;
  ll cnt = 0;
  for(ll i=29; i>=0; i--){
    //cout << i << ": ";
    if(i >= 1 && i <= fctsz-1)
      cnt++;
    //cout << fct[i] << " of " << cnt << " -> " << ch(fct[i], cnt) << endl;
    res *= ch(fct[i], cnt);
    cnt -= fct[i];
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> X;
    factor(X);
    ll res = 0;
    for(int i=29; i>0; i--){
      if(fct[i]){
        fct[i]--;
        res += pos();
        fct[i]++;
      }
    }
    res--;
    cout << res << "\n";
  }

  return 0;
}