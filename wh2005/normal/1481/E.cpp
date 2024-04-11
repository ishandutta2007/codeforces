#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int n,a[N],l[N],r[N],c[N],dp[N],t[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(l,0x3f,sizeof(l));
    for(int i=1;i<=n;i++){
        l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
        c[a[i]]++;t[i]=c[a[i]];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[n]=0;
    for(int i=n;i>=1;i--){
        if(i==r[a[i]]) dp[l[a[i]]-1]=min(dp[l[a[i]]-1],dp[i]+i-l[a[i]]+1-c[a[i]]);
        dp[i-1]=min(dp[i-1],dp[i]+1);
        dp[i-1]=min(dp[i-1],n-i-c[a[i]]+t[i]);
    }
    printf("%d\n",dp[0]);
    return 0;
}