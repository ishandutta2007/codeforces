#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, p, c;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    int lastp=0, lastc=0;
    bool pos = true;
    for(int i=0; i<N; i++){
      cin >> p >> c;
      pos &= p >= lastp && c >= lastc && p-lastp >= c-lastc;
      lastp = p; lastc = c;
    }
    if(pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}