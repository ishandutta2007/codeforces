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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll base=1999925;

ll cnt[maxn];
ll p[maxn][2];
ll pw[maxn];

char s[maxn];

ll solve(int l,int r)
{
    return ((p[r][l%2]-p[l-1][l%2]*pw[cnt[r]-cnt[l-1]]%Mod)%Mod+Mod)%Mod;
}

int main()
{
    sync;
    int n;
    cin>>n;
    cin>>(s+1);
    pw[0]=1ll;
    for(int i=1;i<=n;i++)
    {
        pw[i]=1ll*pw[i-1]*base%Mod;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
            p[i][j]=p[i-1][j];
        cnt[i]=cnt[i-1];
        if(s[i]=='0')
        {
            for(int j=0;j<=1;j++)
            {
                p[i][j]=p[i][j]*base%Mod;
                p[i][j]=(p[i][j]+(i+j)%2+1)%Mod;
            }
            cnt[i]++;
        }
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int L1,L2,len;
        cin>>L1>>L2>>len;
        if(solve(L1,L1+len-1)==solve(L2,L2+len-1))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}