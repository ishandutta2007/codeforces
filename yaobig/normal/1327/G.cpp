#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1010
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;


const int kind=14;
struct AC
{
    int son[maxn+5][kind],fail[maxn+5],v[maxn+5];
    int q[maxn+5];
    //root is 1.
    int tot;
    int newnode()
    {
        tot++;
        memset(son[tot],0,sizeof son[tot]);
        fail[tot]=0;
        v[tot]=0;
        return tot;
    }
    void init()
    {
        tot=0; newnode();
    }
    void insert(char *s,int val)
    {
        int p=1,l=strlen(s);
        rep(i,0,l-1)
        {
            int c=s[i]-'a';
            if(!son[p][c]) son[p][c]=newnode();
            p=son[p][c];
        }
        v[p]+=val;
    }
    void build()
    {
        int rear=-1;
        q[++rear]=1;
        rep(front,0,rear)
        {
            int now=q[front];
            rep(i,0,kind-1)
            {
                int v=son[now][i];
                if(v)
                {
                    int p=fail[now];
                    while(p && !son[p][i]) p=fail[p];
                    fail[v]=p?son[p][i]:1;
                    q[++rear]=v;
                }
            }
        }
        rep(front,0,rear)
        {
            int now=q[front]; v[now]+=v[fail[now]];
        }
        rep(front,0,rear) 
        {
            int now=q[front];
            rep(i,0,kind-1) if(son[now][i]==0)
            {
                if(son[fail[now]][i]) son[now][i]=son[fail[now]][i];
                else son[now][i]=1;
            }
        }
    }
    pair<int,ll> go(int now,char *s,int l)
    {
        ll res=0;
        rep(i,1,l)
        {
            int c=s[i]-'a';
            now=son[now][c];
            res+=v[now];
        }
        return mp(now,res);
    }
}ac;

char s[400000+5];
pair<int,ll> tran[maxn+5][maxn+5];
ll dp[1<<14][maxn+5];

int main()
{    
    ac.init();
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%s",s);
        int val; scanf("%d",&val); 
        ac.insert(s,val);
    }
    ac.build();
    scanf("%s",s+1); n=strlen(s+1);
    int N=-1,prev=0; s[n+1]='?';
    rep(i,1,n+1) if(s[i]=='?')
    {
        N++;
        rep(j,1,ac.tot) tran[N][j]=ac.go(j,s+prev,i-prev-1);
        prev=i;
    }
    //rep(i,0,N) rep(j,1,ac.tot) printf("? %d %d: %d, %lld\n",i,j,tran[i][j].FI,tran[i][j].SE);

    memset(dp,0x80,sizeof dp);
    dp[0][tran[0][1].FI]=tran[0][1].SE;
    int B=1<<14;
    rep(msk,1,B-1)
    {
        int cnt=__builtin_popcount(msk);
        if(cnt>N) continue;
        rep(c,0,13) if(msk&(1<<c))
        {
            int omsk=msk^(1<<c);
            rep(j,1,ac.tot) if(dp[omsk][j]>-1e18)
            {
                ll tmp=dp[omsk][j];
                int now=ac.son[j][c];
                tmp+=ac.v[now]+tran[cnt][now].SE;
                now=tran[cnt][now].FI;
                chmax(dp[msk][now],tmp);
            }
        }
    }
    ll ans=-1e18;
    rep(msk,0,B-1) if(__builtin_popcount(msk)==N) rep(j,1,ac.tot) chmax(ans,dp[msk][j]);
    printf("%lld\n",ans);
    return 0;
}