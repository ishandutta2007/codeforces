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
    int best = sz(S);
    for(char a='0'; a<='9'; a++){
      int cnt = 0;
      for(char c : S)
        if(c != a) cnt++;
      best = min(best, cnt);
    }
    for(char a='0'; a<='9'; a++){
      for(char b='0'; b<='9'; b++){
        int cnt = 0;
        int ind = 0;
        while(true){
          while(ind < sz(S) && S[ind] != a)
            ind++, cnt++;
          if(ind != sz(S)){
            ind++;
            while(ind < sz(S) && S[ind] != b)
              ind++, cnt++;
            if(ind == sz(S))
              cnt++;
            else
              ind++;
          }
          else{
            best = min(best, cnt);
            break;
          }
        }
      }
    }
    cout << best << "\n";
  }
}