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
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> b[i][j];
    }
  }
  for(int k=0;k<n+m-1;k++){
    vector<int> x,y;
    int l=0;
    for(int i=0;i<=k;i++){
      if(i<n&&k-i<m){
        x.push_back(a[i][k-i]);
        y.push_back(b[i][k-i]);
        l++;
      }
    }
    sort(all(x)),sort(all(y));
    for(int i=0;i<l;i++){
      if(x[i]!=y[i]){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}