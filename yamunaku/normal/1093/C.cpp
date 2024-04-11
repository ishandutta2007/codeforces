#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n),b(n/2);
  for(int i=0;i<n/2;i++) scanf("%lld",&b[i]);
  LL pre=INF,pree=0;
  for(int i=0;i<n/2;i++){
    a[i]=max(pree,b[i]-pre);
    a[n-i-1]=b[i]-a[i];
    pre=a[n-i-1];
    pree=a[i];
  }
  for(int i=0;i<n;i++){
    printf("%lld ",a[i]);
  }
  printf("\n");
  return 0;
}