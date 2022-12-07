#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
#define INF 2000000005
using namespace std;
int n,line[maxn],dp[maxn][2];
int DP(int pos,int op){
    if(pos==-1)return op?-INF:0;
    if(dp[pos][op])return dp[pos][op];
    if((line[pos]%2+2)&1){
        return dp[pos][op]=max(DP(pos-1,op^1)+line[pos],DP(pos-1,op));
    }else{
        if(line[pos]<0)return dp[pos][op]=DP(pos-1,op);
        else return dp[pos][op]=DP(pos-1,op)+line[pos];
    }
}
int main(){
    /*freopen("input","r",stdin);
    freopen("output","w",stdout);*/
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&line[i]);
    }
    printf("%d",DP(n-1,1));
    return 0;
}