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

bool vis[N];
void solve()
{
    int d,ret=1;
    cin>>d;
    for(int i=d+1;;i++)
    {
        if(!vis[i])
        {
            d+=i;
            ret*=i;
            break;
        }
    }
    for(int i=d;;i++)
    {
        if(!vis[i])
        {
            ret*=i;
            break;
        }
    }
    cout<<ret<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    for(int i=2;i*i<N;i++)if(!vis[i])
        for(int j=i*i;j<N;j+=i)vis[j]=1;
	int _;
	cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}