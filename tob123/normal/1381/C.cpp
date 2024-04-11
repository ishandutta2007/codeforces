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
  cout << "}" << endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  int N, x, y;
  cin >> T;
  while(T--){
    cin >> N >> x >> y;
    if(x > y || x > N){
      cout << "NO\n";
      continue;
    }
    y -= x;
    vector<vector<int>> M(N+2);
    for(int i=0; i<N; i++){
      int a;
      cin >> a;
      M[a].push_back(i);
    }
    int notOcc = -1;
    vector<vector<int>> occ(N+1);
    for(int i=1; i<=N+1; i++){
      occ[sz(M[i])].push_back(i);
      if(sz(M[i]) == 0)
        notOcc = i;
    }
    int used = 0;
    vector<int> A(N, -1);
    for(int cnt=N; cnt>0; cnt--){
      while(x && sz(occ[cnt])){
        int col = occ[cnt].back();
        occ[cnt].pop_back();
        A[M[col].back()] = col;
        M[col].pop_back();
        occ[cnt-1].push_back(col);
        used++;
        x--;
      }
    }
    bool pos = true;
    for(int cnt=N; cnt>0; cnt--){
      if(sz(occ[cnt]) > 0){
        if((N-used-cnt)*2 < y){
          pos = false;
        }
        break;
      }
    }
    if(!pos){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    auto makeCyc = [&](vector<int> & c){
      for(int i=0; i<sz(c); i++){
        int c1 = c[i], c2 = c[(i+1)%sz(c)];
        A[M[c1].back()] = c2;
        M[c1].pop_back();
      }
      y -= sz(c);
    };
    //print(A);
    //print(M);
    //print(occ);
    //cout << x << " " << y << endl;
    for(int cnt=N; cnt>0; cnt--){
      if(y == 0)
        break;
      if(sz(occ[cnt]) <= y){
        if(sz(occ[cnt]) == 1){
          int nxtI;
          for(nxtI=cnt-1; nxtI>0; nxtI--)
            if(sz(occ[nxtI])) break;
          if(y == 1){
            A[M[occ[nxtI].back()].back()] = occ[cnt].back();
            y--;
            break;
          }
          else{
            vector<int> c;
            c.push_back(occ[cnt][0]);
            c.push_back(occ[nxtI].back());
            makeCyc(c);
            occ[nxtI-1].push_back(occ[nxtI].back());
            occ[nxtI].pop_back();
            occ[cnt-1].push_back(occ[cnt].back());
            occ[cnt].pop_back();
          }
        }
        else{
          makeCyc(occ[cnt]);
          occ[cnt-1].insert(occ[cnt-1].end(), occ[cnt].begin(), occ[cnt].end());
          occ[cnt].clear();
        }
      }
      else{
        if(y == 1){
          A[M[occ[cnt].back()].back()] = occ[cnt][0];
          y--;
          break;
        }
        else{
          vector<int> tmp;
          for(int i=0; i<y; i++){
            tmp.push_back(occ[cnt].back());
            occ[cnt].pop_back();
          }
          makeCyc(tmp);
          occ[cnt-1].insert(occ[cnt-1].end(), tmp.begin(), tmp.end());
        }
      }
    }
    for(int k : A){
      if(k == -1)
        k = notOcc;
      cout << k << " ";
    }
    cout << "\n";
  }
}