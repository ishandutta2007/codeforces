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
const ll Mod=1000000007;
//const ll Mod=998244353;
  


int main()
{
    sync;
    int t;
    cin>>t;
    ll n,k;
    ll al,ar;
    ll bl,br;
    ll L,R;
    ll c1,s1,s2;
    while(t--)
    {
        cin>>n>>k>>al>>ar>>bl>>br;
        if(ar>br)
        {
            swap(al,bl);
            swap(ar,br);
        }
        else if(ar==br)
        {
            if(al>bl)
            {
                swap(al,bl);
                swap(ar,br);
            }
        }
        L=min(al,bl);
        R=max(ar,br);
        ll cost=0ll;
        if(ar<bl)
        {
            cost=1ll*bl-ar;
        }
        s1=max(0ll,1ll*ar-max(bl,al)); //chushi
        c1=2ll*R-br-ar+al+bl-2ll*L;
        s2=1ll*R-L;
        s2-=1ll*s1;
        
        k-=1ll*n*s1;
        if(k<=0)
        {
            cout<<0<<endl;
            continue;
        }
        ll mx=1e18,sum,d;
        for(ll i=1;i<=n;i++)
        {
            d=k;
            sum=1ll*cost*i;
            if(1ll*s2*i>=d)
            {
                sum+=1ll*d;
            }
            else
            {
                sum+=1ll*i*s2+2ll*(d-1ll*i*s2);
            }
            mx=min(sum,mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}