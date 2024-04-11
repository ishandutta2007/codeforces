#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 1e6+9;
int dp[N],g[N];
namespace PAM{
    int lst,tot,n,s[N];
    struct PAM{
        int len,fa,ch[26],slink,dif;
        PAM(){memset(ch,0,sizeof(ch));len=fa=slink=dif=0;}
    }t[N];
    void begin(){s[n=0]='$',tot=1;t[0].fa=1,t[1].len=-1;return ;}
    int getfa(int u){while(s[n]!=s[n-t[u].len-1]) u=t[u].fa;return u;}
    void insert(int c){
        s[++n]=c;
        int now=getfa(lst);
        if(!t[now].ch[c]){
            ++tot;
            t[tot].len=t[now].len+2;
            t[tot].fa=t[getfa(t[now].fa)].ch[c];
            t[now].ch[c]=tot;
            t[tot].dif=t[tot].len-t[t[tot].fa].len;
            if(t[tot].dif==t[t[tot].fa].dif) t[tot].slink=t[t[tot].fa].slink;
            else t[tot].slink=t[tot].fa;
        }
        lst=t[now].ch[c];
        return ;
    }
    void DP(int i){
        for(int x=lst;x>1;x=t[x].slink){
            g[x]=dp[i-t[x].dif-t[t[x].slink].len];
            if(t[x].dif==t[t[x].fa].dif) (g[x]+=g[t[x].fa])%=mod;
            if(i%2==0) (dp[i]+=g[x])%=mod;
        }
        return ;
    }
}

int n;
char s[N],t[N];

int main(){
    PAM::begin();
    scanf("%s",s);n=strlen(s);
    if(n%2){printf("0\n");return 0;}
    for(int i=1,j=0;i<=n&&j<=n;i++) t[++j]=s[i-1],t[++j]=s[n-i];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        PAM::insert(t[i]-'a');PAM::DP(i);
    }
    printf("%d\n",dp[n]);
    return 0;
}