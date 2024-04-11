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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

ll a[N],b[N],c[N];
ll solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    ll ret=0,now=-linf;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==b[i])
        {
            now=c[i]+1;
        }
        else
        {
            now=max(abs(a[i]-b[i])+1,now-abs(a[i]-b[i])+1);
            now+=c[i];
        }
        ret=max(ret,now);
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        cout<<solve()<<endl;
    }
	return 0;
}