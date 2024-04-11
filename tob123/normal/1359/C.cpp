#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  ll H, C, T;
  cin >> t;
  while(t--){
    cin >> H >> C >> T;
    H *= 2; C *= 2; T *= 2;
    if(T >= H){
      cout << 1 << "\n";
    }
    else if(2*T <= H+C){
      cout << 2 << "\n";
    }
    else{
      T -= (H+C)/2;
      double bst = ((H-C)/(2.0*T)-1)/2.0;
      int i1 = (int)bst;
      int i2 = (int)(bst+1);
      //cout << i1 << " " << i2 << endl;
      double dif1 = fabs((H-C)/(2.0*(2*i1+1)) - T);
      double dif2 = fabs((H-C)/(2.0*(2*i2+1)) - T);
      if(dif1 <= dif2){
        cout << 2*i1+1 << "\n";
      }
      else{
        cout << 2*i2+1 << "\n";
      }
    }
  }
}