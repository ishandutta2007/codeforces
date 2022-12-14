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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int solve()
{
    vi v[210];
    int ret=0;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        v[a].push_back(i);
    }
    for(int i=1;i<=200;i++)
    {
        ret=max(ret,(int)v[i].size());
        for(int j=0;j*2+1<v[i].size();j++)
        {
            int ma=0;
            for(int k=1;k<=200;k++)if(k!=i)
            {
                ma=max(ma,upper_bound(v[k].begin(),v[k].end(),v[i][(int)v[i].size()-j-1])-upper_bound(v[k].begin(),v[k].end(),v[i][j]));
            }
            ret=max(ret,ma+j*2+2);
        }
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
    return 0;
}