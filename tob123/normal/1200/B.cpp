#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 110;

int T, N, M, K;
int H[n];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> T;
  while(T--){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
      cin >> H[i];
    }
    bool pos = true;
    for(int i=0; i<N-1; i++){
      M += H[i] - max(0, H[i+1]-K);
      if(M < 0)
        pos = false;
    }
    if(pos)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}