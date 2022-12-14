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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    int a[3],b[3];
    for(int i=0;i<3;i++)cin>>a[i];
    for(int i=0;i<3;i++)cin>>b[i];
    int ans=0;
    for(int i=0;i<3;i++)
    {
        ans+=max(0,a[i]-b[(i+2)%3]-b[i]);
    }
    cout<<ans<<' '<<min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
    return 0;
}