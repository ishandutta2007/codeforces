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
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

struct node
{
    ll id;
    int val;
}a[maxn];

bool cmp(node a,node b)
{
    return a.val>b.val;
}

ll ans[maxn];

int main()
{
    sync;
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        for(ll i=2ll;1ll*i*i<=n;i++)
        {
            if(n%i==0)
            {
                a[++cnt].id=i;
                a[cnt].val=0;
                while(n%i==0)
                {
                    n=1ll*n/i;
                    a[cnt].val++;
                }
            }
        }
        if(n)
        {
            a[++cnt].id=n;
            a[cnt].val=1;
        }
        sort(a+1,a+cnt+1,cmp);
        int sz=a[1].val;
        for(int i=1;i<=sz;i++)
        {
            ans[i]=1ll;
        }
        for(int i=1;i<=cnt;i++)
        {
            ans[sz-a[i].val+1]=1ll*ans[sz-a[i].val+1]*a[i].id;
        }
        for(int i=2;i<=sz;i++)
        {
            ans[i]=1ll*ans[i]*ans[i-1];
        }
        cout<<sz<<endl;
        for(int i=1;i<=sz;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}