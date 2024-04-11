#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int k;
  cin >> k;
  cout << 2000 << endl;
  for(int i=0;i<1998;i++){
    cout << 0 << " ";
  }
  int x=1999-k%1999;
  cout << -x SP (k+x)/1999+x << endl;
  return 0;
}