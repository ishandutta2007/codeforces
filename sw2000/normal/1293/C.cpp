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

int sum[maxn<<2],n;
bool mp[2][maxn];
void add(int p,int v,int o=1,int l=1,int r=n)
{
    if(l==r)
    {
        sum[o]=v;
        return;
    }
    if(p<=mid)add(p,v,lo,l,mid);
    else add(p,v,ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}
void jdg(int a)
{
    if(mp[0][a]&&mp[1][a]||mp[0][a]&&mp[1][a-1]||mp[1][a]&&mp[0][a-1])add(a,1);
    else add(a,0);
}

int main()
{
    // freopen("in.txt","r",stdin);
    int q;cin>>n>>q;
    while(q--)
    {
        int a,b;scanf("%d%d",&a,&b);
        a--;
        mp[a][b]^=1;
        jdg(b);
        if(b!=n)jdg(b+1);
        if(!sum[1])puts("yes");
        else puts("no");
    }
    return 0;
}