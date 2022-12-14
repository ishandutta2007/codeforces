#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int solve()
{
    int n,x,pre[maxn]={0},mi=inf,ma=-inf;
    scanf("%d%d",&n,&x);
    string s;cin>>s;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(s[i-1]=='1')pre[i]--;
        else pre[i]++;
        mi=min(mi,pre[i]);
        ma=max(ma,pre[i]);
    }
    if(pre[n]==0)
    {
        if(x>ma||x<mi)return 0;
        else return -1;
    }
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if((x-pre[i])%pre[n]==0&&(ll)(x-pre[i])*pre[n]>=0)ret++;
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        printf("%d\n",solve());
    }
    return 0;
}