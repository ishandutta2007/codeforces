#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct node{
    int l,r,i;
};
int calc(int l,int r,int *a){
    int res=0;
    for(int i=l;i<=r;i++){
        res=res*10+a[i];
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        map<int,node>mp1;
        map<int,node>mp2;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            int k1=0,k2=0;
            for(int o=1;o<=m;o++){
                int x;
                scanf("%1d",&x);
                k1=k1*10+x;
                k2=k2*10+x;
                k1%=1000;
                k2%=100;
                if(o>=3)mp1[k1]=(node){o-2,o,i};
                if(o>=2)mp2[k2]=(node){o-1,o,i};
            }
        }
        int a[N];
        for(int i=1;i<=m;i++)scanf("%1d",&a[i]);
        int dp[N];
        for(int i=1;i<=m;i++)dp[i]=0;
        dp[0]=1;
        for(int i=1;i<=m;i++){
            if(i>=2&&dp[i-2]&&mp2.find(calc(i-1,i,a))!=mp2.end())dp[i]=2;
            if(i>=3&&dp[i-3]&&mp1.find(calc(i-2,i,a))!=mp1.end())dp[i]=3;
        }
        if(dp[m]){
            int now=m;
            stack<node>s;
            while(now){
                node kk=(dp[now]==2?mp2[calc(now-1,now,a)]:mp1[calc(now-2,now,a)]);
                s.push(kk);
                now-=dp[now];
            }
            printf("%d\n",(int)s.size());
            while(s.size())printf("%d %d %d\n",s.top().l,s.top().r,s.top().i),s.pop();
        }
        else puts("-1");
    }
    return  0;
}