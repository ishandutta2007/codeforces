#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+100;
const ll mod=1e9+7;
const double PI=acos(0)*2;
pii arr[N],brr[N];
int ans[N];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].x>>arr[i].y;
    }
    for(int i=0;i<m;i++)
    {
        cin>>brr[i].x>>brr[i].y;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)if(brr[j].x>=arr[i].x)
        {
            int a=brr[j].x-arr[i].x;
            ans[a]=max(ans[a],max(0,brr[j].y-arr[i].y+1));
        }
    }
    int ret=inf;
    for(int i=N-3;~i;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
        ret=min(ret,i+ans[i]);
    }
//    for(int i=0;i<=10;i++)cout<<i<<' '<<ans[i]<<endl;
    cout<<ret;
    return 0;
}