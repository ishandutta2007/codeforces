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
  cin >> T;
  while(T--){
    cin >> N;
    string S;
    cin >> S;
    int cnt=0, ind=0;
    while(ind < N){
      if(S[ind] == '('){
        if(ind == N-1)
          break;
        ind += 2;
        cnt++;
      }
      else{
        int i2;
        for(i2=ind+1; i2<N && S[i2]!=')'; i2++) ;
        if(i2 != N){
          ind = i2+1;
          cnt++;
        }
        else
          break;
      }
    }
    cout << cnt << " " << N-ind << "\n";
  }
}