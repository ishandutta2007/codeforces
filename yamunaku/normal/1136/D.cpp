#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  vector<set<int>> e(n);
  int u,v;
  for(int i=0;i<m;i++){
    cin >> u >> v;
    e[u-1].insert(v-1);
  }
  vector<int> x;
  x.push_back(p[n-1]);
  int ans=0;
  for(int i=n-2;i>=0;i--){
    bool ng=false;
    for(int j=0;j<x.size();j++){
      if(e[p[i]].find(x[j])==e[p[i]].end()){
        ng=true;
        break;
      }
    }
    if(ng) x.push_back(p[i]);
    else ans++;
  }
  cout << ans << endl;
  return 0;
}