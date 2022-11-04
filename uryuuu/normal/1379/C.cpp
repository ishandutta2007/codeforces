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
//#include<map>
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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn = 100010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

struct node
{
    ll a,b;
}s[maxn];
bool cmp(node a,node b)
{
    return a.a<b.a;
}
ll sum[maxn],c[maxn];

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            cin>>s[i].a>>s[i].b;
        sort(s+1,s+m+1,cmp);
        
        sum[0]=0;
        for(int i=1;i<=m;i++)
        {
            sum[i]=1ll*sum[i-1]+s[i].a;
            c[i]=s[i].a;
        }
        
        ll mx=sum[m]-sum[max(m-n,0)];
        int pos;
        
        ll d,sy;
        for(int i=1;i<=m;i++)
        {
            pos=upper_bound(c+1,c+m+1,s[i].b)-c;
            d=sum[m]-sum[max(m-n,pos-1)];
            sy=n-(m-pos+1);
            if(i<pos&&sy>0)
            {
                sy--;
                d=1ll*d+s[i].a;
            }
            if(sy>0)
                d=1ll*d+1ll*sy*s[i].b;
            mx=max(mx,d);
        }
        cout<<mx<<endl;
    }
    return 0;
}