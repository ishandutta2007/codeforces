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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
//#include <chrono>
//#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int gcd(int a,int b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int a[maxn];
int nxt[maxn];
int b[maxn];
int ans[maxn];
int c[maxn];
bool vis[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        
        int cnt=0;
        for(i=0;i<n;i++)
        {
            b[++cnt]=i;
            nxt[i]=(i+1)%n;
            vis[i]=0;
        }
        
        int tot=0;
        int cc=0;
        int id;
        int u,v;
        while(1)
        {
            cc=0;
            for(i=1;i<=cnt;i++)
            {
                id=b[i];
                if(vis[id])
                    continue;
                u=a[id];
                v=a[nxt[id]];
                if(gcd(u,v)==1)
                {
//                    cout<<u<<' '<<v<<endl;
                    ans[++tot]=nxt[id];
                    c[++cc]=id;
                    vis[nxt[id]]=1;
                    nxt[id]=nxt[nxt[id]];
                }
            }
            if(cc==0)
                break;
            for(i=1;i<=cc;i++)
                b[i]=c[i];
            cnt=cc;
        }
        cout<<tot<<' ';
        for(i=1;i<=tot;i++)
            cout<<ans[i]+1<<' ';
        cout<<endl;
    }
    
    return 0;
}