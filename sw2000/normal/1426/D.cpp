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
const int N=2e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
ll arr[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int n,ans=0;cin>>n;
    set<ll>s;
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(s.count(arr[i]))
        {
            ans++;
            s.clear();
            s.insert(arr[i-1]);
        }
        s.insert(arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}