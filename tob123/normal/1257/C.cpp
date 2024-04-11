#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e6+10;

int T, N;
vector<int> A;
vector<int> V[n];
set<int> S;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    S.clear();
    cin >> N;
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A.push_back(x);
      V[x].push_back(i);
      S.insert(x);
    }
    int m = n;
    for(int x : S){
      if(sz(V[x]) == 1)
        continue;
      int l = V[x][0];
      for(int i=1; i<sz(V[x]); i++){
        m = min(m, V[x][i]-l+1);
        l = V[x][i];
      }
    }
    if(m == n){
      m = -1;
    }
    cout << m << endl;
    for(int x : S){
      V[x].clear();
    }
  }

  return 0;
}