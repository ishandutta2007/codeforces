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
    int n,s,k;
    scanf("%d%d%d",&n,&s,&k);
    map<int,int>m;
    for(int i=0;i<k;i++)
    {
        int a;scanf("%d",&a);
        m[a]=1;
    }
    for(int i=0;;i++)
    {
        if(i+s<=n&&m[i+s]==0)return i;
        if(s-i>=1&&m[s-i]==0)return i;
    }
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