#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define ls i*2
#define rs i*2+1
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vi e[maxn+5];
int dep[maxn+5],euler[maxn*2+5],fi[maxn+5],cnt;
void dfs(int now)
{
    euler[++cnt]=now;
    fi[now]=cnt;
    for(auto v: e[now])
    {
        dep[v]=dep[now]+1;
        dfs(v);
        euler[++cnt]=now;
    }
    return;
}
int lg[maxn*2+5],st[maxn*2+5][18];
int ask(int l,int r)
{
    int k=lg[r-l+1];
    return dep[st[l][k]]<dep[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}

int cmp(int x,int y)
{
    if(fi[x]<fi[y]) return -1;
    if(fi[x]>fi[y]) return 1;
    return 0;
}

struct node
{
    int l,r;
    int M[2],m[2];
}t[maxn*4+5];
int a[maxn+5];
void pushup(int i)
{
    if(cmp(t[ls].M[0],t[rs].M[0])==1)
    {
        t[i].M[0]=t[ls].M[0];
        if(cmp(t[ls].M[1],t[rs].M[0])==1) t[i].M[1]=t[ls].M[1];
        else t[i].M[1]=t[rs].M[0];
    }
    else
    {
        t[i].M[0]=t[rs].M[0];
        if(cmp(t[rs].M[1],t[ls].M[0])==1) t[i].M[1]=t[rs].M[1];
        else t[i].M[1]=t[ls].M[0];
    }
    if(cmp(t[ls].m[0],t[rs].m[0])==-1)
    {
        t[i].m[0]=t[ls].m[0];
        if(cmp(t[ls].m[1],t[rs].m[0])==-1) t[i].m[1]=t[ls].m[1];
        else t[i].m[1]=t[rs].m[0];
    }
    else {
        t[i].m[0]=t[rs].m[0];
        if(cmp(t[rs].m[1],t[ls].m[0])==-1) t[i].m[1]=t[rs].m[1];
        else t[i].m[1]=t[ls].m[0];
    }
}
int _Mid,_mid;
void build(int i,int l,int r)
{
    t[i].l=l;
    t[i].r=r;
    if(l==r)
    {
        t[i].M[0]=t[i].m[0]=l;
        t[i].M[1]=_mid;
        t[i].m[1]=_Mid;
    }
    else
    {
        build(ls,l,(r+l)/2);
        build(rs,(r+l)/2+1,r);
        pushup(i);
    }
    return;
}
int M[2],m[2];
void query(int i,int l,int r)
{
    if(r<t[i].l || t[i].r<l) return;
    if(l<=t[i].l && t[i].r<=r)
    {
        if(cmp(M[0],t[i].M[0])==1)
        {
            if(cmp(M[1],t[i].M[0])==-1) M[1]=t[i].M[0];
        }
        else
        {
            M[1]=M[0];
            M[0]=t[i].M[0];
            if(cmp(M[1],t[i].M[1])==-1) M[1]=t[i].M[1];
        }
        if(cmp(m[0],t[i].m[0])==-1)
        {
            if(cmp(m[1],t[i].m[0])==1) m[1]=t[i].m[0];
        }
        else
        {
            m[1]=m[0];
            m[0]=t[i].m[0];
            if(cmp(m[1],t[i].m[1])==1) m[1]=t[i].m[1];
        }
        //printf("? %d %d %d %d\n",m[0],m[1],M[1],M[0]);
        return;
    }
    query(ls,l,r);
    query(rs,l,r);
}

int main()
{
    lg[1]=0;
    rep(i,2,maxn*2) lg[i]=lg[i>>1]+1;

    int n,q; scanf("%d%d",&n,&q);
    rep(i,2,n)
    {
        int x; scanf("%d",&x);
        e[x].pb(i);
    }
    dfs(1);
    int N=n*2-1;
    rep(i,1,N) st[i][0]=euler[i];
    rep(i,1,lg[N]) rep(j,1,N-(1<<i)+1) st[j][i]=dep[st[j][i-1]]<dep[st[j+(1<<i-1)][i-1]]?st[j][i-1]:st[j+(1<<i-1)][i-1];

    fi[n+1]=-inf;
    fi[n+2]=inf;
    _mid=n+1;
    _Mid=n+2;
    build(1,1,n);
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        M[0]=M[1]=_mid;
        m[0]=m[1]=_Mid;
        query(1,l,r);
        if(dep[ask(fi[m[0]],fi[M[1]])]>dep[ask(fi[m[1]],fi[M[0]])]) printf("%d %d\n",M[0],dep[ask(fi[m[0]],fi[M[1]])]);
        else printf("%d %d\n",m[0],dep[ask(fi[m[1]],fi[M[0]])]);
    }
    return 0;
}