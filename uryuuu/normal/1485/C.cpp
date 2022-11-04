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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn],pre[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll ans=0,d,mid;
        y++;
        ll L,R,l,r;
        for(L=2ll,R;L<=min(x,y);L=R+1ll)
        {
            R=x/(x/L);
            d=x/(L);
            l=L-1;
            r=R-1;
            r=min(r,y-1);
            if(d>=l)
                mid=min(d,r);
            else
                mid=l-1;
            ans=1ll*ans+(l-1ll+mid-1ll)*(mid-l+1)/2ll;
            ans=1ll*ans+(r-mid)*d;
//            cout<<l<<' '<<r<<' '<<d<<' '<<mid<<endl;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}