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
const int mod=1e9+7;

int n,ans[N],q;
int main()
{
    srand(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(!ans[a])ans[a]=i;
    }
    while(q--)
    {
        int t;cin>>t;
        cout<<ans[t]<<' ';
        for(int i=1;i<=50;i++)if(i!=t)
        {
            if(ans[i]<ans[t])ans[i]++;
        }
        ans[t]=1;
    }
	return 0;
}