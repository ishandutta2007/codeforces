#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

pii pnt[100],st;
ll ax,ay,bx,by,t;
int n;

ll dis(pii a,pii b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int solve(int id)
{
    int ret=0;
    for(int i=id;i<n;i++)
    {
        if(dis(pnt[id],pnt[i])+dis(st,pnt[id])<=t)ret=max(ret,i-id+1);
        if(dis(pnt[id],pnt[i])+dis(st,pnt[i])<=t)ret=max(ret,i-id+1);
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    cin>>pnt[0].x>>pnt[0].y;
    cin>>ax>>ay>>bx>>by;
    cin>>st.x>>st.y;
    cin>>t;
    for(int i=1;;i++)
    {
        pnt[i].x=ax*pnt[i-1].x+bx;
        pnt[i].y=ay*pnt[i-1].y+by;
        if(linf/ax<=pnt[i].x||linf/ay<=pnt[i].y)
        {
            n=i;
            break;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,solve(i));
    }
    cout<<ans;

    return 0;
}