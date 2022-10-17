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
  int n,m,h;
  cin >> n >> m >> h;
  vector<int> a(m),b(n);
  for(int i=0;i<m;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  int t;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> t;
      if(t==1){
        cout << min(a[j],b[i]) << " ";
      }else{
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}