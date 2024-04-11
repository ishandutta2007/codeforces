#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, R;
vector<int> X;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> R;
    X.resize(N);
    for(int i=0; i<N; i++){
      cin >> X[i];
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    ll d = 0;
    int cnt = 0;
    for(int i=sz(X)-1; i>=0; i--){
      if(X[i]-d > 0){
        d += R;
        cnt++;
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}