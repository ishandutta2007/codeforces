#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int n = 1e5+10;

ll N, M, K;
vector<int> G[n];
gp_hash_table<int, null_type> Gs[n];
bool aliv[n];
int deg[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
      G[i].clear();
      Gs[i].clear();
      aliv[i] = true;
    }
    for(int i=0; i<M; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
      Gs[u].insert(v);
      Gs[v].insert(u);
    }
    if(M < K*(K-1)/2){
      cout << -1 << "\n";
      continue;
    }
    priority_queue<pii> PQ;
    for(int i=0; i<N; i++){
      deg[i] = sz(G[i]);
      PQ.push(make_pair(-sz(G[i]), i));
    }
    int availCnt = N;
    bool found = false;
    while(!PQ.empty()){
      if(availCnt < K)
        break;
      auto [cnt, ind] = PQ.top();
      PQ.pop();
      cnt *= -1;
      if(cnt != deg[ind])
        continue;
      //cout << "trying " << ind << endl;
      if(cnt == K-1){
        vector<int> cur;
        bool flag = true;
        for(int x : Gs[ind]){
          cur.push_back(x);
          if(deg[x] < K-1){
            flag = false;
            break;
          }
        }
        //cout << "...";print(cur);
        for(int i=0; i<sz(cur); i++){
          for(int j=i+1; j<sz(cur); j++){
            if(Gs[cur[i]].find(cur[j]) == Gs[cur[i]].end()){
              flag = false;
              goto NXT;
            }
          }
        }
NXT: ;
        if(flag){
          found = true;
          cur.push_back(ind);
          cout << 2 << "\n";
          for(int x : cur){
            cout << x+1 << " ";
          }
          cout << "\n";
          break;
        }
      }
      else if(cnt >= K){
        break;
      }
      aliv[ind] = false;
      deg[ind] = -1;
      availCnt--;
      for(int x : Gs[ind]){
        if(aliv[x]){
          deg[x]--;
          Gs[x].erase(ind);
          PQ.push(make_pair(-deg[x], x));
        }
      }
    }
    //cout << found << " " << availCnt << endl;
    if(!found){
      if(availCnt > K){
        cout << 1 << " ";
        vector<int> curRes;
        for(int i=0; i<N; i++){
          if(aliv[i]){
            curRes.push_back(i);
          }
        }
        cout << sz(curRes) << "\n";
        for(int x : curRes)
          cout << x+1 << " ";
        cout << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
  }
}