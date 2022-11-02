#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5 + 10;

int N;
int A[n], B[n], M[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
    M[A[i]] = i;
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
    B[i] = M[B[i]];
  }
  int m = N;
  int cnt = 0;
  for(int i=N-1; i>=0; i--){
    if(m < B[i]){
      cnt++;
    }
    m = min(m, B[i]);
  }
  cout << cnt << endl;

  return 0;
}