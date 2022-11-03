#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M, Q;
string S[200];
string T[200];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> S[i];
  }
  for(int i=0; i<M; i++){
    cin >> T[i];
  }
  cin >> Q;
  for(int i=0; i<Q; i++){
    int y;
    cin >> y;
    cout << S[(y-1)%N] << T[(y-1)%M] << "\n";
  }

  return 0;
}