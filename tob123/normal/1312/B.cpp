#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, T;
vector<int> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    for(int i=0; i<N; i++){
      cout << A[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}