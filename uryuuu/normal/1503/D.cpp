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
#include <chrono>
#include <random>
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
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int f[maxn];
int c[maxn];
int suc[maxn];
int st[2];
int cnt[2];
int cc[2];

int main()
{
    sync;
    int n;
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x<=n&&y<=n)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(x<=n)
        {
            c[x]=y;
            f[x]=0;
        }
        else
        {
            c[y]=x;
            f[y]=1;
        }
    }
    
    suc[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        suc[i]=max(suc[i+1],c[i]);
    }
    
    st[0]=inf;
    st[1]=inf;
    cnt[0]=0;
    cnt[1]=0;
    cc[0]=0;
    cc[1]=0;
    int now=inf;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        now=min(now,c[i]);
        if(st[0]>st[1])
        {
            swap(st[0],st[1]);
            swap(cnt[0],cnt[1]);
            swap(cc[0],cc[1]);
        }
        if(c[i]<st[0])
        {
            st[0]=c[i];
            cnt[0]++;
            cc[0]+=f[i];
        }
        else if(c[i]<st[1])
        {
            st[1]=c[i];
            cnt[1]++;
            cc[1]+=f[i];
        }
        else
        {
            cout<<-1<<endl;
            return 0;
        }
        if(now>suc[i+1])
        {
            ans+=min(cc[0]+cnt[1]-cc[1],cc[1]+cnt[0]-cc[0]);
            st[0]=inf;
            st[1]=inf;
            cnt[0]=0;
            cnt[1]=0;
            cc[0]=0;
            cc[1]=0;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}