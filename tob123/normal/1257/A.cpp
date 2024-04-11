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
  while(T--){
    int N, X, A, B;
    cin >> N >> X >> A >> B;
    int d = abs(A-B);
    d += X;
    d = min(N-1, d);
    cout << d << endl;
  }

  return 0;
}