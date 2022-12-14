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
const int N=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
void solve()
{
    int n,a[110],b[110],c[110];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    int ans[110];
    ans[0]=a[0];
    for(int i=1;i<n-1;i++)
    {
        if(a[i]==a[i-1])a[i]=b[i];
    }
    if(a[n-1]==a[n-2]||a[n-1]==a[0])
    {
        a[n-1]=b[n-1];
        if(a[n-1]==a[n-2]||a[n-1]==a[0])
            a[n-1]=c[n-1];
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        solve();
    return 0;
}