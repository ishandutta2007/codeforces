#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int N, Q;
ll A[n];
ll F[n];
ll sum = 0;
map<pii, int> M;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> A[i];
    sum += A[i];
  }
  cin >> Q;
  while(Q--){
    int s, t, u, b;
    cin >> s >> t >> u;
    auto ind = make_pair(s,t);
    if(M.count(ind)){
      b = M[ind];
      if(b != 0){
        F[b]--;
        if(F[b] < A[b]){
          sum++;
        }
      }
    }
    M[ind] = u;
    if(u != 0){
      F[u]++;
      if(F[u] <= A[u])
        sum--;
    }
    cout << max(1ll, sum) << "\n";
  }

  return 0;
}