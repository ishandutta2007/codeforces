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

const int n = 203;
const int m = n*n+10;

int C[m];
vector<int> cur[n];
bool vis[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  for(int i=0; i<N*K; i++){
    cin >> C[i];
    C[i]--;
  }
  vector<pii> I(N);
  int ind = 0;
  for(int k=0; k<K-1; k++){
    int lft = k < N%(K-1) ? N/(K-1) + 1 : N/(K-1);
    //cout << lft << endl;
    while(lft){
      cur[C[ind]].push_back(ind);
      if(sz(cur[C[ind]]) == 2 && !vis[C[ind]]){
        vis[C[ind]] = true;
        I[C[ind]] = make_pair(cur[C[ind]][0], cur[C[ind]][1]);
        lft--;
        //print(I.back());
      }
      ind++;
    }
    for(int i=0; i<N; i++)
      cur[i].clear();
  }
  for(int i=0; i<N; i++){
    cout << I[i].first+1 << " " << I[i].second+1 << "\n";
  }
}