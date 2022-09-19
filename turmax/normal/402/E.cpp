#include <bits/stdc++.h> 

using namespace std;
#define int long long 
const int maxn=2005;
int parent[maxn];
bool used[maxn];
vector <int> a[maxn];
vector <int> b[maxn];
int timer=0;
int tout[maxn];
int get(int x)
{
	if(parent[x]==(-1)) return x;
	int ans=get(parent[x]);
	parent[x]=ans;
	return ans;
}
void merg(int x,int y)
{
	x=get(x);y=get(y);
	if(x==y) return;
	parent[x]=y;
}
void dfs(int x)
{
	++timer;
	used[x]=1;
	for(auto v:a[x])
	{
		if(!used[v]) dfs(v);
	}
	++timer;
	tout[x]=timer;
}
void dfs1(int x)
{
	used[x]=1;
	for(auto v:b[x])
	{
		if(!used[v]) dfs1(v);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=0;i<maxn;++i) parent[i]=(-1);
	int n;
	cin>>n;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) 
	{
		int x;
		cin>>x; 
        if(x) {merg(i,j);if(i!=j) {a[i].push_back(j);b[j].push_back(i);}}
	}
	set <int> h;
	for(int i=0;i<n;++i) h.insert(get(i));
    if(h.size()>1) {cout<<"NO";return 0;}
    for(int i=0;i<n;++i) if(!used[i]) dfs(i);
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i) v.push_back({tout[i],i});
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    for(int i=0;i<n;++i) used[i]=0;
    dfs1(v[0].second);
    bool ans=1;
    for(int i=0;i<n;++i) ans=(ans && used[i]); 
    if(ans) cout<<"YES";
    else cout<<"NO";
	return 0;
}