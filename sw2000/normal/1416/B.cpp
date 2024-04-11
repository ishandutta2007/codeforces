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
int arr[N];
void solve()
{
    int n,sum=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%n)
    {
        cout<<-1<<endl;
        return;
    }
    sum/=n;
    vector<tri>ans;
    cout<<(n-1)*3<<endl;
    for(int i=2;i<=n;i++)
    {
        int add;
        if(arr[i]%i==0)add=0;
        else add=i-arr[i]%i;
        cout<<1<<' '<<i<<' '<<add<<endl;
        cout<<i<<" "<<1<<' '<<(arr[i]+add)/i<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        cout<<1<<' '<<i<<' '<<sum<<endl;
    }
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