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

const int n = 5e5+10;

int N, M;
vector<int> G[n];
bool used[n];
int TT[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<pii> T(N);
  for(int i=0; i<N; i++){
    cin >> T[i].first;
    T[i].second = i;
    T[i].first--;
    TT[i] = T[i].first;
  }
  sort(T.begin(), T.end());
  for(auto p : T){
    auto [t, i] = p;
    if(sz(G[i]) < t-1){
      cout << -1 << endl;
      return 0;
    }
    for(int j=0; j<=t; j++)
      used[j] = false;
    for(int x : G[i]){
      used[TT[x]] = true;
    }
    bool pos = !used[t];
    for(int j=0; j<t; j++)
      pos &= used[j];
    if(!pos){
      cout << -1 << endl;
      return 0;
    }
  }
  for(auto p : T){
    cout << p.second+1 << " ";
  }
  cout << endl;
}