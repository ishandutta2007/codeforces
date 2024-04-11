#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5;

int N, K;
char A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  A[0] = '0';
  int res = 0;
  int pos = -1;
  for(int i=1; i<=N; i++){
    if(A[(i-1)%K+1] < A[i]){
      res = -1;
      pos = i;
      goto END;
    }
    if(A[(i-1)%K+1] > A[i]){
      res = 1;
      goto END;
    }
  }
  END: ;
  //cout << res << " " << pos << endl;
  if(res == -1){
    pos = K;
    while(A[pos] == '9'){
      A[pos] = '0';
      pos--;
    }
    A[pos]++;
  }
  for(int i=K+1; i<=N; i++){
    A[i] = A[(i-1)%K+1];
  }
  cout << N << endl;
  for(int i=1; i<=N; i++){
    cout << A[i];
  }
  cout << endl;

  return 0;
}