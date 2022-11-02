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
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> s(2, vector<int>(N));
    for(int i=0; i<N; i++){
      int c;
      cin >> c;
      c--;
      s[i<L][c]++;
    }
    for(int i=0; i<N; i++){
      int m = min(s[0][i], s[1][i]);
      s[0][i] -= m;
      s[1][i] -= m;
    }
    int cnt[2] = {0};
    int d[2] = {0};
    for(int i=0; i<2; i++){
      for(int j=0; j<N; j++){
        cnt[i] += s[i][j];
        d[i] += s[i][j] / 2;
      }
    }
    if(cnt[0] > cnt[1]){
      swap(cnt[0], cnt[1]);
      swap(d[0], d[1]);
    }
    int res = cnt[0];
    cnt[1] -= cnt[0];
    int x = min(2*d[1], cnt[1]);
    res += x/2;
    cnt[1] -= x;
    res += cnt[1];
    cout << res << "\n";
  }
}