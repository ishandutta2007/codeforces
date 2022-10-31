#include <bits/stdc++.h>
using namespace std;

int n,dp[101][101][101][2],arr[100];

int DP(int idx,int a,int b,int pre) {
    if(idx==n) return 0;

    int &ret = dp[idx][a][b][pre];
    if(ret!=-1) return ret;

    ret = 200;
    if(arr[idx]) {
        ret = DP(idx+1,a,b,arr[idx]&1) + (pre^(arr[idx]&1));
    } else {
        if(a) ret = min(ret, DP(idx+1,a-1,b,0) + pre);
        if(b) ret = min(ret, DP(idx+1,a,b-1,1) + (pre^1));
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int c[2] = {n/2, (n+1)/2};
    for(int i=0;i<n;i++) if(arr[i]) c[arr[i]%2]--;

    memset(dp,-1,sizeof(dp));
    printf("%d\n",min(DP(0,c[0],c[1],0), DP(0,c[0],c[1],1)));
    
    return 0;
}