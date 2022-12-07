#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,siz,line[maxn],q;
void preprocess(){
    siz=(int)sqrt(n)+1;
}
int dp[maxn][400];
int DP(int pos,int k){
    if(pos>n)return 0;
    if(dp[pos][k])return dp[pos][k];
    return dp[pos][k]=DP(pos+line[pos]+k,k)+1;
}
void Brute_Force(int p,int k){
    int ans=0;
    while(p<=n){
        ans++;
        p=p+line[p]+k;
    }
    printf("%d\n",ans);
}
void Query(int p,int k){
    if(k>siz) Brute_Force(p,k);
    else printf("%d\n",dp[p][k]);
}
int main(){
    /*freopen("input","r",stdin);
    freopen("output","w",stdout);*/
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&line[i]);
    }
    preprocess();
    for(int p=1;p<=n;p++){
        for(int k=1;k<=siz;k++){
            DP(p,k);
        }
    }
    int x,y;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        Query(x,y);
    }
    return 0;
}