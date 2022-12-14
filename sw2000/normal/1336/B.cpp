#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};
int n[3];
ll arr[3][maxn];

ll sum(ll a,ll b,ll c)
{
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}

ll f(int a,int b,int c)
{
    ll ret=linf;
    for(int i=0;i<n[a];i++)
    {
        int x=arr[a][i];
        int y=lower_bound(arr[b],arr[b]+n[b],x)-arr[b];
        if(y==n[b])continue;
        else y=arr[b][y];
        int z=upper_bound(arr[c],arr[c]+n[c],x)-arr[c];
        if(z==0)continue;
        else z=arr[c][z-1];
//        cout<<x<<' '<<y<<" "<<z<<endl;

        ret=min(ret,sum(x,y,z));
    }
    return ret;
}
ll solve()
{
    for(int i=0;i<3;i++)scanf("%d",n+i);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n[i];j++)scanf("%lld",&arr[i][j]);
        sort(arr[i],arr[i]+n[i]);
    }
    ll ret=linf;
    ret=min(ret,f(1,2,0));
    ret=min(ret,f(1,0,2));
    ret=min(ret,f(2,1,0));
    ret=min(ret,f(2,0,1));
    ret=min(ret,f(0,2,1));
    ret=min(ret,f(0,1,2));
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}