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
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  vector<map<int,int>> x(n),y(m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      x[i][a[i][j]]=0;
      y[j][a[i][j]]=0;
    }
  }
  for(int i=0;i<n;i++){
    int now=0;
    for(auto &aaa:x[i]){
      aaa.second=now;
      now++;
    }
  }
  for(int j=0;j<m;j++){
    int now=0;
    for(auto &aaa:y[j]){
      aaa.second=now;
      now++;
    }
  }
  int idx,idy,sx,sy;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      idx=x[i][a[i][j]];
      // cout << x[i].find(a[i][j])->first << endl;
      idy=y[j][a[i][j]];
      sx=x[i].size();
      sy=y[j].size();
      // cout << max(sx-idx,sy-idy) SP max(idx,idy) << " ";
      cout << max(sx-idx,sy-idy)+max(idx,idy) << " ";
    }
    cout << endl;
  }
  return 0;
}