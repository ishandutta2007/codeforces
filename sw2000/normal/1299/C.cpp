#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<double, int> pii;
typedef vector<int> vi;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

pii ans[maxn];
int tot=0,n;
 
int main()
{
    // freopen("in.txt","r",stdin);
    ans[0]={0,0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        ans[++tot]={a,1};
        while(ans[tot].x<=ans[tot-1].x)
        {
            ans[tot-1].x=ans[tot-1].x*ans[tot-1].y+ans[tot].x*ans[tot].y;
            ans[tot-1].y+=ans[tot].y;
            ans[tot-1].x/=ans[tot-1].y;
            tot--;
        }
    }
    for(int i=1;i<=tot;i++)
    {
        for(int j=0;j<ans[i].y;j++)
            printf("%.15lf\n",ans[i].x);
    }
    return 0;
}