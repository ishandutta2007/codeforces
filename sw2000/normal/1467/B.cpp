#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int arr[N],vis[N],n;
bool ok(int i)
{
    if(i==1||i==n)return 0;
    if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])return 1;
    if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])return 1;
    return 0;
}
int solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int ret=0;
    for(int i=2;i<n;i++)
    {
        vis[i]=ok(i);
        ret+=vis[i];
    }
    vis[n]=0;
    int ma=0;
    for(int i=2;i<n;i++)
    {
        int t=arr[i];
        arr[i]=arr[i-1];
        ma=max(ma,vis[i]+vis[i-1]+vis[i+1]-ok(i)-ok(i-1)-ok(i+1));
        arr[i]=arr[i+1];
        ma=max(ma,vis[i]+vis[i-1]+vis[i+1]-ok(i)-ok(i-1)-ok(i+1));
        arr[i]=t;
    }
    return ret-ma;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;

    }
    return 0;
}