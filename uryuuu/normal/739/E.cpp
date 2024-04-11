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
const int maxn=400005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

/*
C(CDP C
 */


int n,a,b;
double p[maxn],q[maxn],dp[maxn];
int numa[maxn],numb[maxn];
const double wc=1e-10;

void ck(double av,double bv) //av,bv
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        numa[i]=numa[i-1];
        numb[i]=numb[i-1];
        if(dp[i]<dp[i-1]+p[i]-av-wc) //
        {
            dp[i]=dp[i-1]+p[i]-av;
            numa[i]=numa[i-1]+1;
            numb[i]=numb[i-1];
        }
        if(dp[i]<dp[i-1]+q[i]-bv-wc)
        {
            dp[i]=dp[i-1]+q[i]-bv;
            numa[i]=numa[i-1];
            numb[i]=numb[i-1]+1;
        }
        if(dp[i]<dp[i-1]+p[i]-av+q[i]-bv-p[i]*q[i]-wc)
        {
            dp[i]=dp[i-1]+p[i]-av+q[i]-bv-p[i]*q[i];
            numa[i]=numa[i-1]+1;
            numb[i]=numb[i-1]+1;
        }
    }
}

double check(double av)
{
    double l=0,r=1,mid;
    for(int i=1;i<=50;i++)
    {
        mid=(l+r)/2.0;
        ck(av,mid);
        if(numb[n]>b)
            l=mid;
        else
            r=mid;
    }
    return l;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>q[i];
    double l=0,r=1,mid,av;
    double bv;
    for(int i=1;i<=50;i++)
    {
        mid=(l+r)/2.0;
        bv=check(mid);
        if(numa[n]>a)
            l=mid;
        else
            r=mid;
    }
    av=l;
    ck(av,bv);
    printf("%.6f\n",dp[n]+av*a+bv*b);
    
    
    return 0;
}