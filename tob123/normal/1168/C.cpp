//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 300003;
const int logn = 20;

int N, Q;

int A[n];
int reach[logn][logn];
int R[n][logn];

void printDP(){
  for(int i=1; i<=N; i++){
    for(int k=0; k<5; k++){
      cout << R[i][k] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  for(int i=0; i<logn; i++){
    for(int j=0; j<logn; j++){
      reach[i][j] = n;
    }
    //reach[i][i] = -1;
  }
  for(int i=N; i>0; i--){
    for(int j=0; j<logn; j++){
      R[i][j] = n;
    }
    for(int j=0, c1=A[i]; j<logn; j++, c1>>=1){
      if(c1&1){
        R[i][j] = i;
      }
    }
    for(int j=0, c1=A[i]; j<logn; j++, c1>>=1){
      if(c1&1){
        for(int k=0, c2=A[i]; k<logn; k++, c2>>=1){
          R[i][k] = min(R[i][k], reach[j][k]);
        }
      }
    }
    for(int j=0, c1=A[i]; j<logn; j++, c1>>=1){
      if(c1&1){
        for(int k=0, c2=A[i]; k<logn; k++, c2>>=1){
          reach[j][k] = min(reach[j][k], R[i][k]);
        }
      }
    }
  }
  //printDP();
  int x, y;
  for(int i=0; i<Q; i++){
    cin >> x >> y;
    bool f = (A[x]&A[y]) > 0;
    for(int k=0, c2=A[y]; k<logn; k++, c2>>=1){
      f |= ((1&c2) > 0) && (R[x][k] <= y);
    }
    if(f)
      cout << "Shi\n";
    else
      cout << "Fou\n";
  }

  return 0;
}