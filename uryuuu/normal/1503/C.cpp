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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;



struct node
{
    ll a,c;
}s[maxn];

bool cmp(node u,node v)
{
    if(u.a==v.a)
        return u.c>v.c;
    return u.a<v.a;
}

int st[maxn];

int main()
{
    sync;
    int n;
    ll sum=0ll;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        sum+=s[i].c;
    }
    sort(s+1,s+n+1,cmp);
    ll ans=0ll;
    ll pre=s[1].a+s[1].c;
    for(int i=2;i<n;i++)
    {
        if(s[i].a+s[i].c>pre)
        {
            ans+=max(0ll,s[i].a-pre);
            pre=s[i].a+s[i].c;
        }
    }
    ans+=max(0ll,s[n].a-pre);
    ans+=sum;
    cout<<ans<<endl;
    
    return 0;
}