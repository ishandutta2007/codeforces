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
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
int n,arr[N];
vector<pii>v[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(auto k:v[arr[i]+arr[j]])
            {
                if(i!=k.se&&i!=k.fi&&j!=k.fi&&j!=k.se)
                {
                    cout<<"YES"<<endl;
                    cout<<k.fi<<' '<<k.se<<' '<<i<<' '<<j;
                    return 0;
                }
            }
            v[arr[i]+arr[j]].push_back({i,j});
        }
    }
    cout<<"NO";
	return 0;
}