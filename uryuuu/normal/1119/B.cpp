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
//#include<unordered_map>
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
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=3010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];
ll zx[maxn];
ll zd[maxn];
ll b[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    sync
    int n;
    ll k;
    cin>>n;
    cin>>k;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    int ans=0;
    int L=1,R=n;
    int mid;
    while(L<R)
    {
        mid=(L+R)/2;
        rep(i,1,mid)
        {
            b[i]=a[i];
        }
        sort(b+1,b+mid+1,cmp);
        ll s=0;
        for(int i=1;i<=mid;i+=2)
        {
            s+=1ll*b[i];
        }
        if(s<=k)
        {
            L=mid+1;
            ans=max(ans,mid);
        }
        else
        {
            R=mid;
        }
    }
    if(ans+1<=n)
    {
        mid=ans+1;
        rep(i,1,mid)
        {
            b[i]=a[i];
        }
        sort(b+1,b+mid+1,cmp);
        ll s=0;
        for(int i=1;i<=mid;i+=2)
        {
            s+=1ll*b[i];
        }
        if(s<=k)
        {
            ans=max(ans,mid);
        }
    }
    cout<<ans<<endl;
    return 0;
}