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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> B(N);
    vector<int> A(N, -1);
    map<int, vector<int>> M;
    for(int i=0; i<N; i++){
      cin >> B[i];
      M[B[i]].push_back(i+1);
    }
    int lst = M[0].size() ? 0 : N+1;
    int sm = lst==N+1;
    int K = 0;
    for(int ind=0; ind<N; ind++){
      auto cur = M[lst];
      for(int i=0; i<sz(cur); i++){
        if(M[cur[i]].size())
          swap(cur[i], cur[sz(cur)-1]);
      }
      for(int i=0; i<sz(cur); i++)
        A[ind+i] = cur[i];
      K += sz(cur) * sm;
      sm = 1-sm;
      lst = cur.back();
      ind += sz(cur)-1;
    }
    cout << K << endl;
    for(int i=0; i<N; i++){
      cout << A[i] << " ";
    }
    cout << endl;
  }
}