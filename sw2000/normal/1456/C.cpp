#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int mod=1e9+7;

int n,k;
ll ans,arr[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+1+n);

    ll add=0;
    while(n&&arr[n]+add>=0)
    {
        ans+=add;
        add+=arr[n--];
    }

    if(n)
    {
        ans+=add;
        k++;
        if(n>k)
        {
            arr[n]+=add;
            for(int i=n;i>k;i--)
            {
                if(i+k<=n)arr[i]+=arr[i+k];
                ans+=arr[i];
            }
        }
    }
//    cout<<ans<<' '<<add<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<' ';
    cout<<ans;
    return 0;
}