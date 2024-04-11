#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long A[1100000];
int f[1100000],n,q,where[1100000],x[1100000];
int solve(long long lim){
    if (A[n]<=lim) return 1;
    int now=n;
    for (int i=n;i;i--){
        while (A[now]-A[i-1]>lim) now--; 
        if (now==n){
            f[i]=0; where[i]=i-1;
        } else {
            where[i]=where[now+1]; f[i]=f[now+1]+1;
        }
    }
    int pre=1,ans=f[1]+1; long long tot=A[n];
    for (int i=1;i<n;i++){
        if (pre<=i) pre++; else tot+=x[i];
        while (tot>lim&&pre<=n){
            tot-=x[pre]; pre++;
        }
        if (pre>n) break;
        ans=min(ans,f[i+1]+1+(where[i+1]<pre-1));
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1); A[i]=k1; x[i]=k1;
    }
    for (int i=1;i<=n;i++) A[i]+=A[i-1];
    for (;q;q--){
        long long k1; scanf("%I64d",&k1); printf("%d\n",solve(k1));
    }
    return 0;
}