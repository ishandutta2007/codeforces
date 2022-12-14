#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

ll mi,sum,ans,n,arr[maxn];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans+=arr[i];
        if(i!=n-1&&i%2==0)sum+=arr[i];
    }
    mi=sum;
    for(int i=n-1;i!=(10*n-3)%n;i=(i+2)%n)
    {
        sum+=arr[i]-arr[(i+1)%n];
        mi=min(mi,sum);
    }
    cout<<ans-mi;
    return 0;
}