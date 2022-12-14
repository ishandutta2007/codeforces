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

void solve()
{
    int n;
    cin>>n;
    int a=n;
    vector<pii>ans;
    for(int i=n-1;i>1;i--)
    {
        if((a-1)/i+1>=i)
        {
            ans.emplace_back(n,i);
            a=(a-1)/i+1;
        }
        while(i==2&&a!=2)
        {
            ans.emplace_back(n,i);
            a=(a-1)/i+1;
        }
        ans.emplace_back(i,n);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i.fi<<' '<<i.se<<endl;
}
int main()
{
//	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
	solve();
	return 0;
}