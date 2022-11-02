#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

ll N;

int main(){
  stack<ll> S;
  ll f = 1;
  cin >> N;
  ll x;
  ll val = 0;
  string s;
  for(int i=0; i<N; i++){
    cin >> s;
    if(s == "for"){
      cin >> x;
      if(f >= 1ll<<32){
        S.push(1);
      }
      else{
        f *= x;
        S.push(x);
      }
    }
    else if(s == "end"){
      x = S.top();
      S.pop();
      f /= x;
    }
    else{
      val += f;
      if(val >= 1ll<<32){
        cout << "OVERFLOW!!!" << endl;
        return 0;
      }
    }
  }
  if(val >= 1ll<<32){
    cout << "OVERFLOW!!!" << endl;
  }
  else{
    cout << val << endl;
  }

  return 0;
}