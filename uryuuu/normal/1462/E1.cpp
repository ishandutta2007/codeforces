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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


int a[maxn];
int vis[maxn];
int b[maxn];
int pre[maxn];


ll C(int n,int m)
{
    ll s=1ll;
    for(int i=1;i<=m;i++)
    {
        s=1ll*s*(1ll*n-1ll*i+1ll);
    }
    for(int i=1;i<=m;i++)
    {
        s=1ll*s/(1ll*i);
    }
    return s;
}



int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    int m,k;
    while(t--)
    {
        cin>>n;
        m=3;
        k=2;
        rep(i,0,n)
        vis[i]=0;
        rep(i,1,n)
        {
            cin>>a[i];
            vis[a[i]]++;
        }
        sort(a+1,a+n+1);
        n=unique(a+1,a+n+1)-a-1;
        pre[0]=0;
        for(int i=1;i<=n;i++)
        {
            b[i]=vis[a[i]];
            pre[i]=pre[i-1]+b[i];
        }
        int pos;
        ll ans=0;
        int L,R;
        for(int i=1;i<=n;i++)
        {
            pos=upper_bound(a+i,a+n+1,a[i]+k)-a-1;
            L=b[i];
            R=pre[pos]-pre[i];
            for(int j=1;j<=m;j++)
            {
                if(j>L||(m-j)>R)
                    continue;
                ans=1ll*ans+1ll*C(L,j)*C(R,(m-j));
            }
            
        }
        cout<<ans<<endl;

    }
    
    
    return 0;
}