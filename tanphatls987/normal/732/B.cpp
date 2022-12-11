#include <bits/stdc++.h>

using namespace std;

int n,k,a[1000];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    int ans=0;
    for(int i=2;i<=n;i++){
        int val=a[i]+a[i-1];
        if (val<=k) ans+=k-val,a[i]+=k-val;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}