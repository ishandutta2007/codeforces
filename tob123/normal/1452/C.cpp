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
  int T;
  cin >> T;
  while(T--){
    string S;
    cin >> S;
    int cnt0 = 0, cnt1 = 0;
    int res = 0;
    for(int c : S){
      if(c == '('){
        cnt0++;
      }
      else if(c == ')' && cnt0 > 0){
        cnt0--;
        res++;
      }
      if(c == '['){
        cnt1++;
      }
      else if(c == ']' && cnt1 > 0){
        cnt1--;
        res++;
      }
    }
    cout << res << "\n";
  }
}