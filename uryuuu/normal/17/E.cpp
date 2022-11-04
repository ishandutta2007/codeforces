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
const int maxn=5000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


string s;
int a[maxn];
int p[maxn];
ll L[maxn],R[maxn];

ll mod=51123987;

int main()
{
    sync;
    int n;
    cin>>n>>s;
    int cnt=1;
    a[0]=27;
    a[1]=0;
    for(int i=0;i<n;i++)
    {
        a[++cnt]=ch(s[i]);
        a[++cnt]=0;
    }
    p[0]=1;
    int id=0;
    for(int i=1;i<=cnt;i++)
    {
        p[i]=p[id]+id>i?min(p[2*id-i],p[id]+id-i):1;
        while(a[i+p[i]]==a[i-p[i]])
            p[i]++;
        if(i+p[i]>id+p[id])
            id=i;
    }
    ll ans=0ll;
    for(int i=1;i<=cnt;i++)
    {
        L[i-p[i]+1]++;
        L[i+1]--;
        R[i]++;
        R[i+p[i]]--;
        ans=(ans+p[i]/2)%mod;
    }
    ans=(1ll*ans*(ans-1ll)/2ll)%mod;
    ll pre=0ll;
    for(int i=1;i<=cnt;i++)
    {
        L[i]+=L[i-1];
        R[i]+=R[i-1];
        if(i%2==0)
        {
            ans-=1ll*pre*L[i]%mod;
            pre=(pre+R[i])%mod;
        }
    }
    
    cout<<(ans%mod+mod)%mod<<endl;
    return 0;
}