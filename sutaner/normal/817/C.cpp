#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long int 
using namespace std;
LL n,s;
LL dp[20][170][2];
bool vis[20][170][2];
int num[25];
LL DP(int pos,int sum,int op){
    if(pos==-1){
        if(sum==0) return 1;
        return 0;
    }
    if(vis[pos][sum][op])return dp[pos][sum][op];
    vis[pos][sum][op]=1;
    LL& ans=dp[pos][sum][op];
    if(op){
        for(int i=0;i<num[pos];i++){
            if(sum<i)break;
            ans+=DP(pos-1,sum-i,0);
        }
        if(sum>=num[pos])ans+=DP(pos-1,sum-num[pos],1);
    }
    else{
        for(int i=0;i<10;i++){
            if(sum<i)break;
            ans+=DP(pos-1,sum-i,0);
        }
    }
    return ans;
}
int main(){
    /*freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);*/
    scanf("%I64d%I64d",&n,&s);
    LL tot=0;
    for(int i=1;i<=162;i++){
        if(s+i>n)break;
        LL temp=n;
        int size=0;
        while(n>0) num[size++]=n%10,n/=10;
        n=temp;
        tot+=DP(size-1,i,1);
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        temp=s+i-1;
        size=0;
        while(temp>0) num[size++]=temp%10,temp/=10;
        tot-=DP(size-1,i,1);
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
    }
    printf("%I64d",tot);
    return 0;
}