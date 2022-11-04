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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;

ll a[maxn],rs[maxn],ls[maxn];
map<ll,int>mp,L,R;

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    rep(i,1,n)
    {
        ls[i]=ls[i-1]+a[i];
        mp[a[i]]++;
        if(L[a[i]]==0)
            L[a[i]]=i;
        R[a[i]]=i;
        if(mp[a[i]]>=k)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=n;i>=1;i--)
    {
        rs[i]=rs[i+1]+a[i];
    }
    int pl, pr;
    ll zx=2e16;
    for(auto f:mp)
    {
        ll x=f.first;
        int num=k-f.second;
        pl=L[x]-1;
        pr=R[x]+1;
        ll Ls=1ll*(x-1)*pl-ls[pl];
        ll Rs=rs[pr]-1ll*(n-pr+1)*(x+1);
        if(num>pl)
        {
            Ls=1ll*Ls+Rs+num;
        }
        else
            Ls+=1ll*num;
        if(num>n-pr+1)
        {
            Rs=1ll*Ls+Rs+num;
        }
        else
            Rs+=1ll*num;
        zx=min(min(Rs,Ls),zx);
    }
    cout<<zx<<endl;
    return 0;
}