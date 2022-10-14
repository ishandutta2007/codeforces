#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=100050;
const int M=2*N;

int a[N],ls[M],rs[M],root,tsz;
ll pref[N],dp[N],mn[M];

void Build(int&c,int ss,int se){
    c=++tsz;
    if(ss==se){mn[c]=a[ss];return;}
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
    mn[c]=min(mn[ls[c]],mn[rs[c]]);
}

ll Get(int c,int ss,int se,int qs,int qe){
    if(ss>se||se<qs||ss>qe)return 1e18;
    if(qs<=ss&&se<=qe)return mn[c];
    int mid=ss+se>>1;
    return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}

int main(){
    int n,c;scanf("%i%i",&n,&c);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
    mn[0]=1e9;Build(root,1,n);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+a[i];
        if(i>=c){
            dp[i]=min(dp[i],dp[i-c]+pref[i]-pref[i-c]-Get(root,1,n,i-c+1,i));
        }
    }
    printf("%lld",dp[n]);
    return 0;
}