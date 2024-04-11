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
  int n;
  cin >> n;
  vector<LL> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  LL ans=0,r=0;
  for(int i=0;i<n;i++){
    if(r<a[i]/2){
      a[i]-=2*r;
      ans+=r;
      r=0;
      ans+=a[i]/3;
      r+=a[i]%3;
    }else{
      ans+=a[i]/2;
      r-=a[i]/2;
      if(a[i]%2) r++;
    }
  }
  cout << ans << endl;
  return 0;
}