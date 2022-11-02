#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    ll sum = 0;
    for(int i=1; i<=N/2; i++){
      sum += 1ll<<i;
    }
    cout << sum << endl;
  }
}