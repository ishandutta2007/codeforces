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
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn];
ll L[maxn],R[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int Ln=0,Rn=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                L[++Ln]=a[i];
            }
            if(a[i]<0)
            {
                R[++Rn]=-a[i];
            }
        }
        sort(L+1,L+Ln+1);
        sort(R+1,R+Rn+1);
        ll Lsum=0,Rsum=0;
        for(int i=Ln;i>=1;i-=k)
        {
            Lsum+=L[i]*2ll;
        }
        for(int i=Rn;i>=1;i-=k)
        {
            Rsum+=R[i]*2ll;
        }
        ll ans=Lsum+Rsum-max(L[Ln],R[Rn]);
        cout<<ans<<endl;
    }
    return 0;
}