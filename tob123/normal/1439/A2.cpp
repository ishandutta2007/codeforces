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
typedef tuple<int,int,int,int,int,int> ti;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> S(N);
    for(int i=0; i<N; i++){
      string z;
      cin >> z;
      for(int j=0; j<M; j++){
        S[i].push_back(z[j] == '1' ? 1 : 0);
      }
    }
    //print(S);
    vector<ti> res;
    for(int i=0; i<N-2; i++){
      for(int j=0; j<M-1; j++){
        vector<pii> cur;
        if(S[i][j+1]){
          cur.emplace_back(i, j+1);
        }
        if(S[i][j]){
          cur.emplace_back(i, j);
        }
        if(sz(cur) == 0)
          continue;
        cur.emplace_back(i+1, j);
        if(sz(cur) < 3)
          cur.emplace_back(i+1, j+1);
        for(auto [y, x] : cur)
          S[y][x] ^= 1;
        res.emplace_back(cur[0].first, cur[0].second, cur[1].first, cur[1].second, cur[2].first, cur[2].second);
      }
    }
    //print(S);
    for(int j=0; j<M-1; j++){
      int i = N-2;
      vector<pii> cur;
      if(S[i+1][j]){
        cur.emplace_back(i+1, j);
      }
      if(S[i][j]){
        cur.emplace_back(i, j);
      }
      if(sz(cur) == 0)
        continue;
      cur.emplace_back(i, j+1);
      if(sz(cur) < 3)
        cur.emplace_back(i+1, j+1);
      for(auto [y, x] : cur)
        S[y][x] ^= 1;
      res.emplace_back(cur[0].first, cur[0].second, cur[1].first, cur[1].second, cur[2].first, cur[2].second);
    }
    //print(S);
    vector<pii> cur, curN;
    for(int i=N-2; i<N; i++){
      for(int j=M-2; j<M; j++){
        if(S[i][j])
          cur.emplace_back(i, j);
        else
          curN.emplace_back(i, j);
      }
    }
    while(sz(cur)){
      vector<pii> nxt;
      if(sz(cur) == 3){
        nxt = cur;
      }
      else if(sz(cur) == 2){
        nxt = curN;
        nxt.push_back(cur[0]);
      }
      else if(sz(cur) == 1){
        nxt = cur;
        nxt.push_back(curN[0]);
        nxt.push_back(curN[1]);
      }
      else{
        cout << "fail" << endl;
      }
      for(auto [y, x] : nxt)
        S[y][x] ^= 1;
      res.emplace_back(nxt[0].first, nxt[0].second, nxt[1].first, nxt[1].second, nxt[2].first, nxt[2].second);
      cur.clear(); curN.clear();
      for(int i=N-2; i<N; i++){
        for(int j=M-2; j<M; j++){
          if(S[i][j])
            cur.emplace_back(i, j);
          else
            curN.emplace_back(i, j);
        }
      }
    }
    cout << sz(res) << "\n";
    for(auto [x1, y1, x2, y2, x3, y3] : res){
      cout << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << " " << x3+1 << " " << y3+1 << "\n";
    }
  }
}