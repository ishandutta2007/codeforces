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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

struct node
{
    ll val,num;
}a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll p,q;
        cin>>p>>q;
        if(p%q)
        {
            cout<<p<<endl;
            continue;
        }
        int cnt=0;
        for(ll i=2ll;i*i<=q;i++)
        {
            if(q%i==0)
            {
                a[++cnt].val=i;
                a[cnt].num=0;
                while(q%i==0)
                {
                    a[cnt].num++;
                    q/=i;
                }
            }
        }
        if(q>1)
        {
            a[++cnt].val=q;
            a[cnt].num=1;
        }
        ll ans=0;
        for(int i=1;i<=cnt;i++)
        {
            ll d=p;
            while(d%a[i].val==0)
            {
                d/=a[i].val;
            }
            for(int j=1;j<a[i].num;j++)
            {
                d=1ll*d*a[i].val;
            }
            ans=max(d,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}