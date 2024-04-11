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
const int maxn=2005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn][maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>n>>k;
        int i,j;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=n;j++)
                a[i][j]=0;
        }
        a[k][1]=1ll;
        ll ans=0ll;
        int f=k%2;
        ll sum=0;
        for(i=k;i>=1;i--)
        {
            if(i%2==f)
            {
                sum=a[i][1];
                for(j=2;j<=n;j++)
                {
                    a[i-1][j]=sum;
                    sum=(1ll*sum+a[i][j])%Mod;
                }
            }
            else
            {
                sum=a[i][n];
                for(j=n-1;j>=1;j--)
                {
                    a[i-1][j]=sum;
                    sum=(1ll*sum+a[i][j])%Mod;
                }
            }
        }
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=n;j++)
                ans=(1ll*ans+a[i][j])%Mod;
        }
        if(k>1)
            ans=ans+1ll;
        cout<<(ans%Mod+Mod)%Mod<<endl;
    }
    
    return 0;
}