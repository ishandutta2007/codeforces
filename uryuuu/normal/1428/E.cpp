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
const double pi=acos(-1);
const int maxn=300010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

struct node
{
    ll d,val,s;
    bool operator<(const node& a)const
    {
        return val<a.val;
    }
}b[maxn];

ll a[maxn];

ll qry(ll d,ll s)
{
    ll x=s/d;
    ll m=s%d;
    ll s1=m*(x+1)*(x+1)+(d-m)*x*x;
    d++;
    x=s/d;
    m=s%d;
    ll s2=m*(x+1)*(x+1)+(d-m)*x*x;
    return s1-s2;
}

int main()
{
    sync;
    int n,k;
    ll sum=0;
    cin>>n>>k;
    priority_queue<node>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum=1ll*sum+1ll*a[i]*a[i];
        b[i].s=a[i];
        b[i].d=1;
        b[i].val=qry(1,a[i]);
        q.push(b[i]);
    }
    
//    while(q.size())
//    {
//        node g=q.top();
//        q.pop();
//        cout<<g.d<<' '<<g.s<<' '<<g.val<<endl;
//    }
    
//    cout<<sum<<endl;
    for(int i=n+1;i<=k;i++)
    {
        node g=q.top();
        q.pop();
//        cout<<g.d<<' '<<g.s<<' '<<g.val<<endl;
        sum-=g.val;
        g.d++;
        if(g.d<g.s)
        {
            g.val=qry(g.d,g.s);
            q.push(g);
        }
    }
    cout<<sum<<endl;
    
    return 0;
}