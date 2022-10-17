#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n,m;
  cin >> n >> m;
  vector<LL> a(n+1);
  a[0]=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  vector<LL> total(n+2);
  if(n%2){
    total[n]=total[n+1]=0;
    for(int i=n-1;i>=0;i-=2){
      if(i>0){
        total[i]=total[i-1]=a[i+1]-a[i]+total[i+2];
      }else{
        total[i]=a[i+1]-a[i]+total[i+2];
      }
    }
  }else{
    total[n]=total[n-1]=m-a[n];
    for(int i=n-2;i>=0;i-=2){
      if(i>0){
        total[i]=total[i-1]=a[i+1]-a[i]+total[i+2];
      }else{
        total[i]=a[i+1]-a[i]+total[i+2];
      }
    }
  }
  LL ans=total[0];
  for(int i=0;i<n;i++){
    if(a[i+1]>a[i]+1){
      if(i%2){
        ans=max(ans,total[0]-total[i]+m-a[i]-1-total[i+1]);
      }else{
        ans=max(ans,total[0]-total[i]+a[i+1]-a[i]-1+m-a[i+1]-total[i+1]);
      }
    }
  }
  if(m>a[n]+1){
    ans=max(ans,total[0]-total[n]+m-a[n]-1);
  }
  cout << ans << endl;
  return 0;
}