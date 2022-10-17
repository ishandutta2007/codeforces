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
  LL n,k,m;
  cin >> n >> m >> k;
  vector<LL> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(all(a),greater<LL>());
  cout << m/(k+1)*(a[0]*k+a[1])+m%(k+1)*a[0] << endl;
  return 0;
}