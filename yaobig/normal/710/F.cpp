#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 600000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct AC
{
	#define C 26
    int next[maxn+5][C],msk[maxn+5],fail[maxn+5],cnt[maxn+5],sum[maxn+5];
    int tot;
    int newnode()
    {
        tot++;
        memset(next[tot],0,sizeof next[tot]);
        msk[tot]=0;
        fail[tot]=0;
        cnt[tot]=sum[tot]=0;
        return tot;
    }
    void insert(int rt,char *s)
    {
        int now=rt,l=strlen(s);
        rep(i,0,l-1)
        {
            int c=s[i]-'a';
            if(next[now][c]==0) next[now][c]=newnode(),msk[now]|=1<<c;
            now=next[now][c];
        }
        cnt[now]++;
    }
    void build(int rt)
    {
        queue<int> q; q.push(rt);
        while(q.size())
        {
            int now=q.front(); q.pop();
            for(int b=msk[now];b;b-=b&-b)
            {
                int i=__builtin_ctz(b&-b);
                int son=next[now][i];
                int p=fail[now];
                while(p && next[p][i]==0) p=fail[p];
                fail[son]=p?next[p][i]:rt;
                q.push(son);
            }
            sum[now]=cnt[now]+sum[fail[now]];
        }
    }
    int merge(int x,int y) // merge y to x.
    {
        if(x==0 || y==0) return x | y;
        cnt[x]+=cnt[y];
        msk[x]|=msk[y];
        for(int b=msk[y];b;b-=b&-b)
        {
            int i=__builtin_ctz(b&-b); 
            next[x][i]=merge(next[x][i],next[y][i]);
        }
        return x;
    }
    ll query(int rt,char *s)
    {
        int now=rt,l=strlen(s);
        ll ans=0;
        rep(i,0,l-1)
        {
            int c=s[i]-'a';
            while(now && next[now][c]==0) now=fail[now];
            now=now?next[now][c]:rt;
            ans+=sum[now];
        }
        return ans;
    }
    #undef C
}ac;

struct block
{
    int rt[25],num[25],top;
    void ins(char *s)
    {
        rt[++top]=ac.newnode(); num[top]=1;
        ac.insert(rt[top],s);
        while(top>1 && num[top]==num[top-1])
        {
            rt[top-1]=ac.merge(rt[top-1],rt[top]);
            num[top-1]+=num[top];
            top--;
        }
        ac.build(rt[top]);
    }
    inline ll ask(char *s)
    {
        ll ans=0;
        rep(i,1,top) ans+=ac.query(rt[i],s);
        return ans; 
    }
}A,D;

char s[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int op; scanf("%d%s",&op,s);
        if(op==1) A.ins(s);
        else if(op==2) D.ins(s);
        else
        {
            ll ans=A.ask(s)-D.ask(s);
            printf("%lld\n",ans);
            fflush(stdout);
        }
    }
    return 0;
}