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
  int n;
  cin >> n;
  vector<int> a(n);
  int ma=0;
  for(int i=0;i<n;i++) cin >> a[i],ma=max(ma,a[i]);
  int ans=0,tmp=0;
  for(int i=0;i<n;i++){
    if(a[i]==ma){
      tmp++;
    }else{
      ans=max(ans,tmp);
      tmp=0;
    }
  }
  ans=max(ans,tmp);
  cout << ans << endl;
  return 0;
}