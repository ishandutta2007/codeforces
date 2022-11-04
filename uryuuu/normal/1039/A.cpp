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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

ll a[maxn];
ll x[maxn];
ll b[maxn];
int lst[maxn];

int main()
{
    sync;
    ll t;
    int n;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>x[i];
    
    for(int i=2;i<=n;i++)
    {
        if(x[i-1]>x[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(x[i]<i)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        b[i]=3e18-1ll*(n-i);
    }
    
    for(int i=n-1;i>=1;i--)
    {
        if(x[i]!=x[i+1])
            b[x[i]]=min(b[x[i]],a[i+1]+t-1);
    }
    
    for(int i=n-1;i>=1;i--)
    {
        b[i]=min(b[i],b[i+1]-1ll);
    }
    
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=mx)
        {
            lst[i]=1;
        }
        mx=max(x[i],1ll*i);
    }
    
    
    
    for(int i=2;i<=n;i++)
    {
        if(lst[i])
        {
            if(a[i]+t>b[i-1])
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]+t>b[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]+t>b[x[i]])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    
    
    return 0;
}