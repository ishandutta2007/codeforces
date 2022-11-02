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

const int n = 1e6+10;

vector<int> F[n];
bool np[n];

void init(){
  for(int i=2; i<n; i++){
    if(!np[i]){
      F[i].push_back(i);
      for(int j=2*i; j<n; j+=i){
        np[j] = true;
        int cnt = 0;
        int x = j;
        while(x % i == 0){
          x /= i;
          cnt++;
        }
        if(cnt%2){
          F[j].push_back(i);
        }
      }
    }
  }
}

int main(){
  init();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N, Q;
    cin >> N;
    vector<ll> A(N);
    map<vector<int>, int> M;
    for(int i=0; i<N; i++){
      cin >> A[i];
      //cout << A[i] << " ";
      //print(F[A[i]]);
      M[F[A[i]]]++;
    }
    int bst = 0;
    int sum = 0;
    for(auto [k, v] : M){
      bst = max(bst, v);
      if(v%2 == 0 || sz(k) == 0)
        sum += v;
    }
    sum = max(sum, bst);
    cin >> Q;
    for(int i=0; i<Q; i++){
      ll x;
      cin >> x;
      if(x == 0)
        cout << bst << "\n";
      else
        cout << sum << "\n";
    }
  }
}