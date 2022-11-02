#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, T;
vector<int> A, B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--){
    cin >> N;
    A.resize(N);
    B.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    for(int i=0; i<N; i++){
      cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<N; i++){
      cout << " " << A[i];
    }
    cout << endl;
    for(int i=0; i<N; i++){
      cout << " " << B[i];
    }
    cout << endl;
  }

  return 0;
}