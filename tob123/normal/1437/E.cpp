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

const int INF = 1.5e9;

int N, K;
vector<int> A, B;
bool pos = true;

int calc(int a, int b){
  if(A[b] < A[a]){
    pos = false;
    return 0;
  }
  vector<pii> S;
  S.emplace_back(A[a], 0);
  for(int i=a+1; i<b; i++){
    if(A[i] >= A[a] && A[i] <= A[b]){
      auto it = upper_bound(S.begin(), S.end(), make_pair(A[i], INF));
      it--;
      int cur = it->second + 1;
      if(sz(S) > cur){
        S[cur].first = min(S[cur].first, A[i]);
      }
      else
        S.emplace_back(A[i], cur);
    }
  }
  //cout << a << " " << b << " -> " << sz(S) << endl;
  return b-a-1-sz(S)+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N+2); B.resize(K+2);
  A[0] = -1e6;
  A[N+1] = INF;
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  B[0] = 0; B[K+1] = N+1;
  for(int j=1; j<=K; j++){
    cin >> B[j];
  }
  for(int i=0; i<sz(A); i++)
    A[i] -= i;
  //print(A);
  int res = 0;
  for(int i=0; i<=K; i++){
    res += calc(B[i], B[i+1]);
  }
  if(pos)
    cout << res << "\n";
  else
    cout << "-1\n";
}