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


struct node
{
    ll x,y,f;
}a[maxn];

int p[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }

    
    ll x=0,y=0;
    ll sum1,sum2;
    int id;
    while(1)
    {
        x=0ll;
        y=0ll;
        random_shuffle(p+1,p+n+1);
        for(int i=1;i<=n;i++)
        {
            id=p[i];
            sum1=1ll*(x+a[id].x)*(x+a[id].x)+1ll*(y+a[id].y)*(y+a[id].y);
            sum2=1ll*(x-a[id].x)*(x-a[id].x)+1ll*(y-a[id].y)*(y-a[id].y);
            if(sum1<=sum2)
            {
                a[id].f=1;
            }
            else
                a[id].f=-1;
            x+=a[id].f*a[id].x;
            y+=a[id].f*a[id].y;
        }
        if(x*x+y*y<=1500000ll*1500000ll)
        {
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].f<<' ';
    }
    cout<<endl;
    return 0;
}