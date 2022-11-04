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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll b[50];
ll a[50];

int main()
{
    sync;
    int t;
    ll x;
    cin>>t;
    b[0]=2ll;
    for(int i=1;i<=40;i++)
    {
        b[i]=2ll*b[i-1];
    }
    for(int i=0;i<=40;i++)
    {
        b[i]-=1ll;
    }
    while(t--)
    {
        mm(a);
        cin>>x;
        ll n=lower_bound(b+1,b+38,x)-b;
        x-=1ll*n;
        x-=1ll;
        ll st=1ll;
        for(ll i=0;i<n;i++)
        {
            a[i]=min(1ll*x/(1ll*n-i),1ll*st);
//            cout<<x<<endl;
            x-=1ll*a[i]*(1ll*n-i);
            st+=1ll*a[i];
//            cout<<x<<endl;
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    
    
    return 0;
}