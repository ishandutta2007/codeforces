#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const ll bas = 37;
const int N = 2e6+9;
int n,m;
char s[N],a[N];
ll hs[N],mi[N];
ll geths(int l,int r){return (hs[r]-hs[l-1]*mi[r-l+1]%mod+mod)%mod;}
map<ll ,int >mp;

int las,cnt;
struct SAM{
    int len,fa,ch[26];
    SAM(){memset(ch,0,sizeof(ch));len=fa=0;}
}t[N];
void insert(int c){
    int p=las,np=las=++cnt;t[np].len=t[p].len+1;
    for(;p&&!t[p].ch[c];p=t[p].fa) t[p].ch[c]=np;
    if(!p) t[np].fa=1;
    else{
        int q=t[p].ch[c];
        if(t[q].len==t[p].len+1) t[np].fa=q;
        else{
            int nq=++cnt;t[nq]=t[q];
            t[nq].len=t[p].len+1;
            t[q].fa=t[np].fa=nq;
            for(;p&&t[p].ch[c]==q;p=t[p].fa) t[p].ch[c]=nq;
        }
    }
    return ;
}
int head[N],tot,f[N];
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
void dfs(int u){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v);f[u]+=f[v];
    }
    return ;
}

int main(){
    mi[0]=1;for(int i=1;i<=N-9;i++) mi[i]=mi[i-1]*bas%mod;
    las=cnt=1;
    memset(f,0,sizeof(f));
    scanf("%s",s);n=strlen(s);
    for(int i=0;i<n;i++){insert(s[i]-'a');f[las]=1;}
    memset(head,-1,sizeof(head));tot=0;
    for(int i=2;i<=cnt;i++) add(t[i].fa,i);
    dfs(1);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);m=strlen(a+1);mp.clear();
        for(int j=1;j<=m;j++) a[j+m]=a[j];
        for(int j=1;j<=(m<<1);j++) hs[j]=(hs[j-1]*bas%mod+a[j]-'a'+1)%mod;
        int u=1,l=0;ll ans=0;
        for(int j=1;j<=(m<<1);j++){
            while(u!=1&&!t[u].ch[a[j]-'a']){
                u=t[u].fa,l=min(l,t[u].len);
            }
            if(t[u].ch[a[j]-'a']){
                u=t[u].ch[a[j]-'a'],l++;
                if(j>m&&l>=m&&!mp[geths(j-m+1,j)]){
                    int p=u;
                    while(t[t[p].fa].len+1>m){
                        p=t[p].fa;
                    }   
                    ans+=f[p];
                    mp[geths(j-m+1,j)]=1;
                }
            }
            else u=1;
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}