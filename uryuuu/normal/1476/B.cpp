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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;



ll p[111];
ll sum[111];
int main()
{
    sync;
    ll n,k;
    int t;
    cin>>t;
    while(t--)
    {
        mm(sum);
        ll ans=0;
        cin>>n>>k;
        rep(i,1,n)
            cin>>p[i];
        sum[1]=p[1];
        for(int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1]+p[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(p[i]*100ll>sum[i-1]*k)
            {
                ll tmp=(100ll*p[i]+k-1)/k-sum[i-1];
                ans+=tmp;
                for(int j=1;j<=n;j++)
                {
                    sum[j]+=tmp;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}