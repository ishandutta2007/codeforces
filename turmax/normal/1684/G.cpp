#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1005;
bool a[maxn][maxn];
bool used[maxn];
int mt[maxn];
int n1,n2;
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (int to=0;to<n2;++to)
    {
		if(a[v][to])
        {
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
        }
	}
	return false;
}
vector<pair<int,int> > res;
void go(int x,int y)
{
    res.push_back({2*x+y,x+y});
}
void go(int x)
{
    res.push_back({3*x,2*x});
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;int a1[n];for(int i=0;i<n;++i) cin>>a1[i];
    int ma=*max_element(a1,a1+n);if(2*ma+1>m) {cout<<(-1);return 0;}
    vector<int> v1,v2;
    for(int i=0;i<n;++i) {int x=a1[i];if(3*x>m) {v1.push_back(x);} else {v2.push_back(x);}}
    //for(auto h:v1) cout<<h<<" h1 "<<endl;
    //for(auto h:v2) cout<<h<<" h2 "<<endl;
    n1=v1.size();n2=v2.size();
    for(int i=0;i<n1;++i)
    {
        for(int j=0;j<n2;++j)
        {
            if(v1[i]*2+v2[j]<=m && v1[i]%v2[j]==0)
            {
                a[i][j]=true;
            }
        }
    }
    for(int i=0;i<maxn;++i) mt[i]=(-1);
    for (int v=0; v<n1; ++v) {
		for(int i=0;i<maxn;++i) {used[i]=false;}
		try_kuhn (v);
	}
	int sz1=0;
    for(int i=0;i<n2;++i)
    {
        if(mt[i]!=(-1))
        {
            ++sz1;
            go(v1[mt[i]],v2[i]);
        }
        else
        {
            go(v2[i]);
        }
    }
    if(sz1!=n1) {cout<<(-1);return 0;}
    cout<<res.size()<<'\n';
    for(auto h:res) {cout<<h.first<<' '<<h.second<<'\n';}
    return 0;
}