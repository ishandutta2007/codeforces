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
const int N=3e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
int n,arr[N],pre[N],ma[N],ans[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pre[i]=0;
        ma[i]=-1;
        ans[i]=inf;
    }
    for(int i=1;i<=n;i++)
    {
        ma[arr[i]]=max(ma[arr[i]],i-pre[arr[i]]);
        pre[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)ma[i]=max(ma[i],n+1-pre[i]);
    for(int i=n;i;i--)
    {
        ans[ma[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=min(ans[i-1],ans[i]);
        if(ans[i]==inf)cout<<-1<<' ';
        else cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    ans[0]=inf;
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}