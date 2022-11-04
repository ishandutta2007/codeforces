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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
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
const int maxn=300005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int b[maxn];
void upd(int x,int val)
{
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

int qry(int x)
{
    int res=0;
    while(x)
    {
        res+=b[x];
        x-=lb(x);
    }
    return res;
}

int a[maxn];
int c[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0ll;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[i]=a[i];
        }
        sort(c+1,c+n+1);
        int m=unique(c+1,c+n+1)-c-1;
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(c+1,c+m+1,a[i])-c;
        }
        int L,R;
        for(int i=1;i<=n;i++)
        {
            L=qry(a[i]-1);
            R=i-1-qry(a[i]);
//            cout<<L<<' '<<R<<endl;
            ans+=1ll*min(L,R);
            upd(a[i],1);
        }
        for(int i=1;i<=n;i++)
            upd(a[i],-1);
        cout<<ans<<endl;
    }
    return 0;
}