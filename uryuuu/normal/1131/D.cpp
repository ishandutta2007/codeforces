#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


vector<int>g[4010],p[4040];
string s;
int a[1010][1010];
int d[4020],b[4020];
int father[4030];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

int siz[4020];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='>')
                a[i][j+1]=1;
            else if(s[j]=='<')
                a[i][j+1]=-1;
            else
                a[i][j+1]=0;
        }
    }
    
    for(int i=1;i<=n+m;i++)
        father[i]=i;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                g[i].push_back(j+n);
                d[j+n]++;
            }
            else if(a[i][j]==-1)
            {
                g[j+n].push_back(i);
                d[i]++;
            }
            else
            {
                jihe(i,j+n);
            }
        }
    }
    
    for(int i=1;i<=n+m;i++)
    {
        p[getf(i)].push_back(i);
        siz[getf(i)]++;
    }
    

    int f=0;
    int sum=0;
    queue<pii>q;
    int fa;
    int u,cnt,v;
    for(int i=1;i<=n+m;i++)
    {
        if(d[i]==0)
        {
            fa=getf(i);
            siz[fa]--;
            if(siz[fa]==0)
            {
                for(int j=0;j<p[fa].size();j++)
                {
                    v=p[fa][j];
                    b[v]=-1;
                    sum++;
                    q.push(mkp(v,b[v]));
                }
            }
        }
    }
    
    int x;
    while(q.size())
    {
        u=q.front().first;
        cnt=q.front().second;
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(b[v])
                continue;
            d[v]--;
            if(d[v]==0)
            {
                fa=getf(v);
                siz[fa]--;
                if(siz[fa]==0)
                {
                    for(int j=0;j<p[fa].size();j++)
                    {
                        x=p[fa][j];
                        b[x]=b[u]-1;
                        sum++;
                        q.push(mkp(x,b[x]));
                    }
                }
            }
        }
    }
    
    if(sum!=n+m)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    int mx=0;
    for(int i=1;i<=n+m;i++)
    {
        mx=min(b[i],mx);
    }
    for(int i=1;i<=n+m;i++)
    {
        b[i]=b[i]-mx+1;
        cout<<b[i]<<' ';
        if(i==n)
            cout<<endl;
    }
    cout<<endl;
    
    
    return 0;
}