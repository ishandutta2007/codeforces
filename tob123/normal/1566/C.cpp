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
  int T, N;
  vector<string> s(2);
  cin >> T;
  while(T--){
    cin >> N;
    cin >> s[0] >> s[1];
    bool last1 = true;
    ll sum = 0;
    bool cur1 = false;
    for(int i=0; i<N; i++){
      int cur = s[0][i]-'0' + s[1][i]-'0';
      if(cur == 1){
        sum += 2;
        last1 = true;
        cur1 = false;
      }
      if(cur == 2){
        if(last1){
          cur1 = true;
        }
        else{
          last1 = true;
          sum++;
        }
      }
      if(cur == 0){
        sum++;
        if(cur1){
          sum++;
          last1 = true;
        }
        else
          last1 = false;
        cur1 = false;
      }
    }
    cout << sum << "\n";
  }
}