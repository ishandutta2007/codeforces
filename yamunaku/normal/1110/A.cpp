#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int b,k;
  cin >> b >> k;
  LL ans=0;
  int a;
  for(int i=0;i<k-1;i++){
    cin >> a;
    ans=(ans+a*b)%2;
  }
  cin >> a;
  ans=(ans+a)%2;
  if(ans%2) cout << "odd" << endl;
  else cout << "even" << endl;
  return 0;
}