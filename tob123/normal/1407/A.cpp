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
    vector<int> res;
    vector<int> A(N);
    int lst1 = -1;
    int cnt1 = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
      if(A[i] == 1){
        if(lst1 != -1 && lst1 == sz(res)%2){
          res.pop_back();
        }
        lst1 = sz(res)%2;
        cnt1++;
      }
      res.push_back(A[i]);
    }
    cout << (cnt1%2 ? sz(res)-1 : sz(res)) << endl;
    for(int i=0; i<sz(res); i++){
      if(res[i] == 1 && cnt1%2){
        cnt1 = 0;
        continue;
      }
      cout << res[i] << " ";
    }
    cout << "\n";
  }
}