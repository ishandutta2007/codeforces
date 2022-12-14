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
int n,m,arr[N];
int solve()
{
    cin>>n>>m;
    map<int,int>mp;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        mp[a%m]++;
    }
    for(auto i:mp)
    {
        if(i.fi==0)ret++;
        else if(i.fi+i.fi==m)ret++;
        else if(mp.find(m-i.fi)==mp.end())
        {
            ret+=i.se;
        }
        else if(i.fi+i.fi<m)
        {
            ret++;
            ret+=max(0,abs(i.se-mp[m-i.fi])-1);
        }
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