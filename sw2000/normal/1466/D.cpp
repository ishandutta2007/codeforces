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

int n;
ll arr[N],du[N];
void solve()
{
    ll ret=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        du[i]=0;
        ret+=arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        du[a]++;
        du[b]++;
    }
    priority_queue<ll>q;
    for(int i=1;i<=n;i++)
    {
        while(du[i]!=1)
        {
            q.push(arr[i]);
            du[i]--;
        }
    }
    cout<<ret<<' ';
    while(!q.empty())
    {
        ret+=q.top();
        q.pop();
        cout<<ret<<' ';
    }
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