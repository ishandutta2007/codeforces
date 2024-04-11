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
typedef pair<ll, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve()
{
    int n,ans[110][110]{};
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=1;j<=(n-1)/2;j++)
        ans[i][(i+j)%n]=1,ans[i][(i-j+n)%n]=-1;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)cout<<ans[i][j]<<' ';
    cout<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}