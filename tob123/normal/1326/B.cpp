#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<int> A, B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  B.resize(N);
  for(int i=0; i<N;i++){
    cin >> B[i];
  }
  A.resize(N);
  int mx = 0;
  for(int i=0; i<N;i++){
    A[i] = B[i]+mx;
    mx = max(mx, A[i]);
  }
  for(int x : A){
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}