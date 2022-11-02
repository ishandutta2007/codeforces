#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int N;
  vector<int> A;
  while(T--){
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    cout << unique(A.begin(), A.end())-A.begin() << "\n";
  }

  return 0;
}