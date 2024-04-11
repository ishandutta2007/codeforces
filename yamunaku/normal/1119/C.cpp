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
  int at,bt;
  for(int i=0;i<n;i++){
    at=bt=0;
    for(int j=0;j<m;j++){
      at+=a[i][j];
      bt+=b[i][j];
    }
    if(at%2!=bt%2){
      cout << "No" << endl;
      return 0;
    }
  }
  for(int j=0;j<m;j++){
    at=bt=0;
    for(int i=0;i<n;i++){
      at+=a[i][j];
      bt+=b[i][j];
    }
    if(at%2!=bt%2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}