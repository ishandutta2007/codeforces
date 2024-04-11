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
const int N = 5000 + 10;
const int mod = 1e9 + 7;

int n,tag[N];
ll f[N],s[N];
ll solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>tag[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j;j--)if(tag[i]!=tag[j])
        {
            ll tmp=f[i]+abs(s[i]-s[j]);
            f[i]=max(f[i],f[j]+abs(s[i]-s[j]));
            f[j]=max(f[j],tmp);
        }
    }

    ll ret=0;
    for(int i=1;i<=n;i++)ret=max(ret,f[i]);
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