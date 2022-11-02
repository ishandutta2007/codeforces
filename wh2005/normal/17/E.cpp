#include<bits/stdc++.h>
using namespace std;
const int mod = 51123987;
const int N = 2e6+9;
namespace PAM{
    int lst,tot,n,s[N],dep[N],len[N],fa[N];
    int slink[N],dif[N],dp[N],g[N],ans;
    int head[N],tt;
    struct pp{int nxt,to,val;}G[N];
    void add(int u,int v,int w){
        G[++tt].nxt=head[u],G[tt].to=v,G[tt].val=w,head[u]=tt;return ;
    }
    void begin(){
        memset(head,-1,sizeof(head));tt=0;
        s[n=0]='$',tot=1;fa[0]=1,len[1]=-1;return ;
    }
    int getfa(int u){while(s[n]!=s[n-len[u]-1]) u=fa[u];return u;}
    int getch(int u,int c){
        for(int i=head[u];i!=-1;i=G[i].nxt){
            int v=G[i].to;if(G[i].val==c) return v;
        }
        return 0;
    }
    void insert(int c){
        s[++n]=c;
        int now=getfa(lst);
        if(!getch(now,c)){
            ++tot;
            len[tot]=len[now]+2;
            fa[tot]=getch(getfa(fa[now]),c);
            dep[tot]=dep[fa[tot]]+1;
            dif[tot]=len[tot]-len[fa[tot]];
            if(dif[tot]==dif[fa[tot]]) slink[tot]=slink[fa[tot]];
            else slink[tot]=fa[tot];
            add(now,tot,c);
        }
        lst=getch(now,c);
        return ;
    }
    void DP(int i){
        for(int x=lst;x>1;x=slink[x]){
            g[x]=dp[i-dif[x]-len[slink[x]]];
            if(dif[x]==dif[fa[x]]) (g[x]+=g[fa[x]])%=mod;
            (ans+=g[x])%=mod;
        }
        dp[i]=(dp[i-1]+dep[lst])%mod;
        return ;
    }
}

int n;
char s[N];

int main(){
    PAM::begin();
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        PAM::insert(s[i]-'a');
        PAM::DP(i);
    }
    int sum=PAM::dp[n],opp=PAM::ans;
    int ans=(1ll*sum*(sum-1)/2%mod+mod-opp)%mod;
    printf("%d\n",ans);
    return 0;
}
/*
g++ CF17E.cpp -o A



1+2+3+2+1

*/