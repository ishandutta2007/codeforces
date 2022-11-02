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
    int N, M;
    cin >> N >> M;
    if(N > M)
      swap(N,M);
    if(M%N == 0){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }


  return 0;
}