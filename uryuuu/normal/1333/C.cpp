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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];
ll s[maxn];
int r[maxn];
map<ll,int>mp;
int b[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    s[0]=0ll;
    rep(i,1,n)
    s[i]=s[i-1]+a[i];
    rep(i,1,n)
    {
        if(a[i]==0)
            r[i]=i;
        else
            r[i]=9999999;
    }
    for(int i=n;i>=1;i--)
    {
        if(mp[s[i-1]])
        {
            r[i]=mp[s[i-1]];
        }
        mp[s[i]]=i;
        if(a[i]==0)
            r[i]=i;
    }
    ll sum=0;
    int zx=n;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<r[i]<<' ';
//    }
//    cout<<endl;
    for(int i=n;i>=1;i--)
    {
        zx=min(zx,r[i]-1);
        if(a[i])
            sum+=1ll*(zx-i+1);
//        cout<<sum<<' '<<zx<<endl;
    }
    cout<<sum<<endl;
    
    return 0;
}