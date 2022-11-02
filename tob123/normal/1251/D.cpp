#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<ll,ll> pii;

const ll INF = 1e16;

int N, T;
ll S;
vector<pii> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> S;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i].first >> A[i].second;
      S -= A[i].first;
    }
    sort(A.begin(), A.end());
    ll l = 0, r = INF;
    while(l < r){
      ll m = (l+r+1)/2;
      ll curS = S;
      int cnt = 0;
      for(int i=N-1; i>=0; i--){
        if(A[i].first >= m){
          cnt++;
        }
        else if(A[i].second >= m && m-A[i].first <= curS){
          cnt++;
          curS -= m-A[i].first;
        }
      }
      if(cnt >= N/2 + 1){
        l = m;
      }
      else{
        r = m-1;
      }
    }
    cout << l << "\n";
  }

  return 0;
}