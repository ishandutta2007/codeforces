#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M, K;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> K;
  int cnt = N-1+M-1 + 2*(N/2*M);
  if(N%2)
    cnt += M-1;
  cout << cnt << endl;
  for(int i=0; i<N-1; i++){
    cout << "U";
  }
  for(int i=0; i<M-1; i++){
    cout << "L";
  }
  for(int i=0; i<N/2; i++){
    for(int i=0; i<M-1; i++){
      cout << "R";
    }
    cout << "D";
    for(int i=0; i<M-1; i++){
      cout << "L";
    }
    cout << "D";
  }
  if(N%2){
    for(int i=0; i<M-1; i++){
      cout << "R";
    }
  }
  cout << endl;

  return 0;
}