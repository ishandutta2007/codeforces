#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long dp[N][N],n,m,x[N];
struct node{
    long long p,c;
    bool operator<(const node b)const{
        return p<b.p;
    }
}dat[N];
long long calc(int o,int i){
    return labs(x[o]-dat[i].p);
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
    }
    stable_sort(x+1,x+n+1);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&dat[i].p,&dat[i].c);
    }
    stable_sort(dat+1,dat+m+1);
    memset(dp,63,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        long long val[N];
        val[0]=0;
        for(int o=1;o<=n;o++)val[o]=val[o-1]+calc(o,i);
        int h=0,t=1,q[N];
        for(int o=0;o<=n;o++){
            while(h>=t&&dp[i-1][q[h]]+val[n]-val[q[h]]>=dp[i-1][o]+val[n]-val[o])h--;
            q[++h]=o;
            while(h>=t&&o-q[t]>dat[i].c)t++;
            dp[i][o]=dp[i-1][q[t]]+val[o]-val[q[t]];
        }
    }
    printf("%lld",dp[m][n]>=1e18?-1ll:dp[m][n]);
    return  0;
}