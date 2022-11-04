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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=40005;
const ll Mod=1000000007;

ll a[maxn],b[maxn],sa[maxn],sb[maxn];
ll s[maxn];

int main()
{
    sync;
    int n,m;
    ll k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sa[i]=sa[i-1]+a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        sb[i]=sb[i-1]+b[i];
    }
    int cnt=0;
    for(ll i=1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            s[cnt++]=i;
            if(i*i!=k)
                s[cnt++]=k/i;
        }
    }
    ll x,y;
    ll sum=0;
    ll sn,sm;
    for(int r=0;r<cnt;r++)
    {
        x=s[r];
        y=k/s[r];
        if(x>n||y>m)
            continue;
        sn=0;
        sm=0;
        for(int i=x;i<=n;i++)
        {
            if(sa[i]-sa[i-x]==x)
                sn++;
        }
        for(int i=y;i<=m;i++)
        {
            if(sb[i]-sb[i-y]==y)
                sm++;
        }
        sum+=sn*sm;
    }
    cout<<sum<<endl;
    return 0;
}