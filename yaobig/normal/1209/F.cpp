#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5][10];
int mark[maxn+5];

vi q[maxn+5];
int ans[maxn+5];

int N;
void add(int x,int y,int i)
{
    int last=y;
    while(i>=10)
    {
        e[++N][i%10].pb(last);
        i/=10;
        last=N;
    }
    e[x][i].pb(last);
}

int main()
{
    int n,m; scanf("%d%d",&n,&m); 
    N=n;
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y); 
        add(x,y,i);
        add(y,x,i);
    }
    int rear=-1; mark[1]=1;
    q[++rear].pb(1);
    rep(front,0,rear) rep(d,0,9)
    {
        int ok=0;
        for(auto now: q[front]) for(auto v: e[now][d]) if(mark[v]==0)
        {
            if(ok==0) ok=1,rear++;
            q[rear].pb(v);
            mark[v]=1;
            ans[v]=(10ll*ans[now]+d)%mod;
        }
    }
    rep(i,2,n) printf("%d\n",ans[i]);
    return 0;
}