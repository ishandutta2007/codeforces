#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll N, C, S;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> C >> S;
    ll a = S - S/C*C;
    ll b = C-a;
    ll res = b * (S/C)*(S/C) + a * (S/C + 1) * (S/C + 1);
    cout << res << endl;
  }

  return 0;
}