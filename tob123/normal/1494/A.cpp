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

bool check(string& s, char c){
  int sign = -1;
  if(s[0] == c) sign = 1;
  int sum = 0;
  for(auto x : s){
    if(x == c){
      sum += sign;
    }
    else
      sum -= sign;
    if(sum < 0)
      return false;
  }
  return sum == 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  string S;
  cin >> T;
  while(T--){
    cin >> S;
    if(check(S, 'A') || check(S, 'B') || check(S, 'C')){
      cout << "YES\n";
    }
    else
      cout << "NO\n";
  }
}