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

ll a[maxn],pre[maxn],q[maxn];
ll b[maxn],c[maxn];

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        ll mx=-2e18;
        cin>>n>>m;
        b[0]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
            mx=max(pre[i],mx);
            if(pre[i]>b[cnt])
            {
                b[++cnt]=pre[i];
                c[cnt]=i;
            }
        }
        
        ll x;
        int pos;
        ll d;
        
        while(m--)
        {
            cin>>x;
            if(mx>=x)
            {
                pos=lower_bound(b+1,b+cnt+1,x)-b;
                cout<<c[pos]-1<<' ';
                continue;
            }
            if(pre[n]<=0)
            {
                cout<<-1<<' ';
                continue;
            }
            d=(x-mx)/pre[n];
            if((x-mx)%pre[n])
            {
                d++;
            }
            x=x-d*pre[n];
            pos=lower_bound(b+1,b+cnt+1,x)-b;
            cout<<1ll*d*n+c[pos]-1<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}