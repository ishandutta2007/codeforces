#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+9;
int n,a[N];



int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=1ll*a[i]*(n-a[i]+1);
    for(int i=1;i<n;i++){
        int x=a[i],y=a[i+1];if(x>y) swap(x,y);
        ans-=1ll*x*(n-y+1);
    }
    printf("%lld\n",ans);
    return 0;
}