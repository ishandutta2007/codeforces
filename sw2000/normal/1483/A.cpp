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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int n,m;
vi v[N];
void solve()
{
    cin>>n>>m;
    map<int,int>mp;
    for(int i=0;i<m;i++)
    {
        int k;cin>>k;
        while(k--)
        {
            int a;cin>>a;
            v[i].push_back(a);
        }
        if(v[i].size()==1)mp[v[i][0]]++;
    }
    for(auto i:mp)
    {
        if(i.se>(m+1)/2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<m;i++)if(v[i].size()>1)
    {
        for(auto j:v[i])
        {
            if(mp[j]<(m+1)/2)
            {
                cout<<j<<' ';
                mp[j]++;
                break;
            }
        }
    }
    else cout<<v[i][0]<<' ';
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
        for(int i=0;i<m;i++)v[i].clear();
    }

	return 0;
}