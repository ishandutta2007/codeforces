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
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn],b[maxn],c[maxn];

map<int,ll>mp;

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
    
    int mx=2e9;
    for(int i=n;i>=1;i--)
    {
        c[i]=min(a[i],mx);
        mx=min(c[i],mx);
        mp[c[i]]++;
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<c[i]<<' ';
//    }
    ll sum=1ll;
    if(mx!=b[1])
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=m;i++)
    {
        sum=1ll*mp[b[i]]*sum%Mod;
    }
    cout<<sum<<endl;
    return 0;
}