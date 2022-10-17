#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL gcd(LL x,LL y){
  while(x%y){
    LL tmp=x%y;
    x=y;
    y=tmp;
  }
  return y;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<LL> x(n),p(m);
  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  LL g=x[1]-x[0];
  for(int i=1;i<n-1;i++){
    g=gcd(g,x[i+1]-x[i]);
  }
  for(int i=0;i<m;i++){
    cin >> p[i];
    if(g%p[i]==0){
      cout << "YES" << endl;
      cout << x[0] SP i+1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}