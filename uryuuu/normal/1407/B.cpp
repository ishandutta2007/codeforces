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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
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

ll a[maxn];
int vis[maxn];
ll ans[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,1,n)
        cin>>a[i];
        int L,R;
        ll mx=0;
        ll gd;
        if(n==1)
        {
            cout<<a[1]<<endl;
            continue;
        }
        rep(i,1,n)
        vis[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(mx<a[i])
            {
                L=i;
                mx=a[i];
            }
        }
        ans[1]=L;
        vis[L]=1;
        ll temp=mx;
        for(int k=2;k<=n;k++)
        {
            mx=0;
            for(int i=1;i<=n;i++)
            {
                if(vis[i])
                    continue;
                gd=gcd(a[i],temp);
                if(gd>mx)
                {
                    L=i;
                    mx=gd;
                }
            }
            temp=mx;
            ans[k]=L;
            vis[L]=1;
        }
        for(int i=1;i<=n;i++)
            cout<<a[ans[i]]<<' ';
        cout<<endl;
    }
    
    return 0;
}