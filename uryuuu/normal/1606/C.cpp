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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn];
ll pw[maxn];

int main()
{
    sync;
    pw[0]=1ll;
    for(int i=1;i<=10;i++)
    {
        pw[i]=pw[i-1]*10ll;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        k++;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]=pw[a[i]];
        }
        ll ans=0;
        ll now=0,lmt,s;
        for(int i=1;i<n;i++)
        {
            lmt=a[i+1]/a[i]-1;
            s=min(k,lmt);
            now+=s;
            ans+=1ll*s*a[i];
            k-=s;
            if(k==0)
                break;
        }
        ans+=1ll*k*a[n];
        cout<<ans<<endl;
    }
    return 0;
}