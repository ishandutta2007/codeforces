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
const int mod = 998244353;

int n,k;
set<int>edg[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        edg[u].insert(v);
        edg[v].insert(u);
    }
    vi v;
    for(int i=1;i<=n;i++)if(edg[i].size()==1)v.push_back(i);
    while(k--)
    {
        if(v.empty())
        {
            cout<<"No";
            return 0 ;
        }
        map<int,int>mp;
        vi tmp;
        for(auto i:v)
        {
            int u=*edg[i].begin();
            edg[i].erase(u);
            edg[u].erase(i);
            mp[u]++;
            if(edg[u].size()==1)tmp.push_back(u);
            if(edg[u].size()==0)tmp.clear();
        }
        swap(tmp,v);
        for(auto i:mp)
        {
            if(i.se<3)
            {
                cout<<"No";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)if(edg[i].size())
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
	return 0;
}