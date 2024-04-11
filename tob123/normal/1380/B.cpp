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
  string S;
  cin >> T;
  while(T--){
    cin >> S;
    int r=0, s=0, p=0;
    for(char c : S){
      if(c == 'R')
        r++;
      else if(c == 'S')
        s++;
      else
        p++;
    }
    int m = max(max(r, s), p);
    char c = 'S';
    if(r == m)
      c = 'P';
    else if(s == m)
      c = 'R';
    for(int i=0; i<sz(S); i++)
      cout << c;
    cout << "\n";
  }
}