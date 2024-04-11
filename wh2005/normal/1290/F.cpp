#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long 
#define ri int
#define pii pair<int,int>
int n,m;
const ll mod=998244353;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
int dp[32][32][32][32][32][2][2];
int x[5],y[5];
int DP(int pos,int a,int b,int c,int d,int p,int q){
    if((m>>pos)==0) return a==0&&b==0&&c==0&&d==0&&p==0&&q==0;
    if(~dp[pos][a][b][c][d][p][q]) return dp[pos][a][b][c][d][p][q];
    dp[pos][a][b][c][d][p][q]=0;
    int cur=m>>pos&1;
    for(ri s=0;s<(1<<n);++s){
        int A=a,B=b,C=c,D=d;
        for(ri i=0;i<n;++i){
            if(!(s>>i&1)) continue;
            if(x[i]<0) C-=x[i];
            else A+=x[i];
            if(y[i]<0) D-=y[i];
            else B+=y[i];
        }
        if((A&1)^(C&1)) continue;
        if((B&1)^(D&1)) continue;
        int rp=p,rq=q;
        if(cur^(A&1)) rp=cur^1;
        if(cur^(B&1)) rq=cur^1;
        dp[pos][a][b][c][d][p][q]=add(dp[pos][a][b][c][d][p][q],DP(pos+1,A>>1,B>>1,C>>1,D>>1,rp,rq));
    }
    return dp[pos][a][b][c][d][p][q];
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(ri i=0;i<n;++i) scanf("%d%d",&x[i],&y[i]);
    printf("%lld\n",dec(DP(0,0,0,0,0,0,0),1));
}