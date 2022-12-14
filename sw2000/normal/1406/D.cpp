#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

ll n,arr[maxn],in;

void put(ll a)
{
    if(a>=0)
    {
        cout<<(a+1)/2<<endl;
    }
    else if(a<0)
    {
        cout<<a/2<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=n;i>1;i--)
    {
        arr[i]-=arr[i-1];
        if(arr[i]>0)in+=arr[i];
    }
    put(arr[1]+in);
    int m;cin>>m;
    while(m--)
    {
        int l,r,x;cin>>l>>r>>x;
        if(l!=1&&arr[l]>0)
        {
            in-=arr[l];
        }
        arr[l]+=x;
        if(l!=1&&arr[l]>0)in+=arr[l];
        if(r!=n)
        {
            if(arr[r+1]>0)in-=arr[r+1];
            arr[r+1]-=x;
            if(arr[r+1]>0)in+=arr[r+1];
        }
        put(arr[1]+in);
    }
    return 0;
}