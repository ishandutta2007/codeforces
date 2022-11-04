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
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod=998244353;

ll d[10];
ll c[10];


int main()
{
    sync;
    int t;
    cin>>t;
    ll x,y;
    while(t--)
    {
        cin>>x>>y;
        for(int i=1;i<=6;i++)
            cin>>d[i];
        c[1]=min(d[1],d[2]+d[6]);
        c[2]=min(d[2],d[1]+d[3]);
        c[3]=min(d[3],d[2]+d[4]);
        c[4]=min(d[4],d[3]+d[5]);
        c[5]=min(d[5],d[4]+d[6]);
        c[6]=min(d[6],d[5]+d[1]);
        
        ll ans=0ll;
        ll mn;
        if(x>0&&y>0)
        {
            mn=min(x,y);
            ans+=1ll*c[1]*mn;
            x-=mn;
            y-=mn;
        }
        if(x<0&&y<0)
        {
            mn=max(x,y);
            ans-=1ll*c[4]*mn;
            x-=mn;
            y-=mn;
        }
        
        ans+=1ll*max(0ll,y)*c[2];
        ans+=1ll*max(0ll,x)*c[6];
        ans-=1ll*min(0ll,y)*c[5];
        ans-=1ll*min(0ll,x)*c[3];
        cout<<ans<<endl;
    }
    
    return 0;
}