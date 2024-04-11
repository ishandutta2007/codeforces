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


long long gcd(long long a,long long b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll a[maxn],b[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    ll gd;
    if(n==1)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<a[1]+b[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
    
    gd=1ll*a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        gd=gcd(gd,1ll*a[i]-a[i-1]);
    }
//    cout<<gd<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<gcd(gd,a[1]+b[i])<<' ';
    }
    cout<<endl;
    
    return 0;
}