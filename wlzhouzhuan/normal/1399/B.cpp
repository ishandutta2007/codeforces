#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=55;
ll a[N],b[N];
int n;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    ll mina=1e9,minb=1e9;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),mina=min(mina,a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]),minb=min(minb,b[i]);
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=max(a[i]-mina,b[i]-minb);
    printf("%lld\n",ans);
  }
  return 0;
}