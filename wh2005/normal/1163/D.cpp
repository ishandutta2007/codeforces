#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<cassert>
#include<algorithm>
#include<ctime>
#include<random>

using namespace std;
mt19937 rd(time(0));

#define ri int
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const ll mod=998244353;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}


char c[1024],s[64],t[64];
int n,x,y;
int transs[64][26],transt[64][26],nxt[64];
int dp[2][64][64];
int main(){
    scanf("%s",c+1);n=strlen(c+1);
    {
        scanf("%s",s+1),x=strlen(s+1);
        transs[0][s[1]-'a']=1;
        memset(nxt,0,sizeof(nxt));
        for(ri i=1,j=0;i<=x;++i){
            while(j&&s[i]!=s[j+1]) j=nxt[j];
            if(i>1&&s[i]==s[j+1]) ++j;
            nxt[i]=j;
            memcpy(transs[i],transs[j],sizeof(transs[i]));
            if(i<x) transs[i][s[i+1]-'a']=i+1;
            // for(ri k=0;k<26;++k) printf("[%d %d]=%d\n",i,k,transs[i][k]);
        }
    }
    {
        scanf("%s",t+1),y=strlen(t+1);
        transt[0][t[1]-'a']=1;
        memset(nxt,0,sizeof(nxt));
        for(ri i=1,j=0;i<=y;++i){
            while(j&&t[i]!=t[j+1]) j=nxt[j];
            if(i>1&&t[i]==t[j+1]) ++j;
            nxt[i]=j;
            memcpy(transt[i],transt[j],sizeof(transt[i]));
            if(i<y) transt[i][t[i+1]-'a']=i+1;
        }
    }
    memset(dp,-0x3f,sizeof(dp));
    int o=0;
    dp[o][0][0]=0;
    for(ri i=0;i<n;++i){
        memset(dp[o^1],-0x3f,sizeof(dp[o^1]));
        if(c[i+1]=='*'){
            for(ri j=0;j<=x;++j) for(ri k=0;k<=y;++k){
                for(ri C=0;C<26;++C){
                    int res=dp[o][j][k]+(transs[j][C]==x)-(transt[k][C]==y);
                    dp[o^1][transs[j][C]][transt[k][C]]=max(dp[o^1][transs[j][C]][transt[k][C]],res);
                    // if(res>-10) printf("[%d %d %d]->[%d %d %d]=%d\n",i,j,k,i+1,transs[j][C],transt[k][C],res);
                }
            }
        }
        else{
            int C=c[i+1]-'a';
            for(ri j=0;j<=x;++j) for(ri k=0;k<=y;++k){
                int res=dp[o][j][k]+(transs[j][C]==x)-(transt[k][C]==y);
                dp[o^1][transs[j][C]][transt[k][C]]=max(dp[o^1][transs[j][C]][transt[k][C]],res);
                // if(res>-10) printf("[%d %d %d]->[%d %d %d]=%d\n",i,j,k,i+1,transs[j][C],transt[k][C],res);
            }
        }
        o^=1;
        // for(ri j=0;j<=x;++j) for(ri k=0;k<=y;++k) printf("[%d %d %d]=%d\n",i+1,j,k,dp[o][j][k]);
    }
    int ans=-1e9;
    for(ri i=0;i<=x;++i) for(ri j=0;j<=y;++j) ans=max(ans,dp[o][i][j]);
    printf("%d\n",ans);
}