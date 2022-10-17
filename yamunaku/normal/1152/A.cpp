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
  int a1=0,a2=0,b1=0,b2=0;
  int x;
  for(int i=0;i<n;i++){
    cin >> x;
    if(x%2) a1++;
    else a2++;
  }
  for(int i=0;i<m;i++){
    cin >> x;
    if(x%2) b1++;
    else b2++;
  }
  cout << min(a1,b2)+min(a2,b1) << endl;
  return 0;
}