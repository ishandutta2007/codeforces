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
  int T, N, K;
  string S;
  cin >> T;
  while(T--){
    cin >> N >> K >> S;
    vector<vector<char>> occ(N, vector<char>(2));
    for(int i=0; i<N; i++){
      if(S[i] == '0')
        occ[i%K][0] = true;
      if(S[i] == '1')
        occ[i%K][1] = true;
    }
    if(K%2){
      cout << "NO\n";
      continue;
    }
    bool res = true;
    int cnt1=0, cnt2=0;
    for(int i=0; i<K; i++){
      cnt1 += occ[i][0];
      cnt2 += occ[i][1];
      res &= !occ[i][0] || !occ[i][1];
    }
    if(cnt1*2 <= K && cnt2*2 <= K && res){
      cout << "YES\n";
    }
    else
      cout << "NO\n";
  }
}