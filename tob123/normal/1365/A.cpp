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

const int n = 150;

int T, N, M;
bool vis1[n];
bool vis2[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M;
    for(int i=0; i<max(N, M); i++)
      vis1[i] = vis2[i] = false;
    int cntR=N, cntC=M;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        bool x;
        cin >> x;
        if(x && !vis1[i])
          cntR--, vis1[i] = true;
        if(x && !vis2[j])
          cntC--, vis2[j] = true;
      }
    }
    if(min(cntR, cntC)%2){
      cout << "Ashish\n";
    }
    else{
      cout << "Vivek\n";
    }
  }
}