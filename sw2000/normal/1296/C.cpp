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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

void solve()
{
    int n;scanf("%d",&n);
    string s;cin>>s;
    ll pre[maxn]={0};
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i];
        if(s[i]=='L')pre[i+1]+=1;
        else if(s[i]=='R')pre[i+1]-=1;
        else if(s[i]=='U')pre[i+1]+=maxn;
        else pre[i+1]-=maxn;
    }

    map<ll,int>m;
    m[0]=0;
    int l=-1,r=maxn;
    for(int i=1;i<=n;i++)
    {
        if(m.count(pre[i])&&i-m[pre[i]]<r-l)
        {
            r=i;
            l=m[pre[i]];
        }
        m[pre[i]]=i;
    }
    if(l==-1)puts("-1");
    else printf("%d %d\n",l+1,r);

}
 
int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}