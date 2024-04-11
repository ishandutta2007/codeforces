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

vector<int> cmp;

int find(int x){
  if(cmp[x] != x)
    return cmp[x] = find(cmp[x]);
  return cmp[x];
}

void uni(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b){
    cmp[a] = b;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int M, N;
  cin >> M >> N;
  vector<ll> A(M), B(N);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  cmp.resize(N+M);
  iota(cmp.begin(), cmp.end(), 0);
  vector<tuple<int,int,int>> E;
  ll tot = 0;
  for(int i=0; i<M; i++){
    int s = 0;
    cin >> s;
    for(int j=0; j<s; j++){
      int x;
      cin >> x;
      x--;
      E.emplace_back(A[i]+B[x], i, x);
      tot += A[i]+B[x];
    }
  }
  sort(E.rbegin(), E.rend());
  for(auto [c, a, b] : E){
    if(find(b) != find(a+N)){
      tot -= c;
      uni(b, a+N);
    }
  }
  cout << tot << "\n";
}