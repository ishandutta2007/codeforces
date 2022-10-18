#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

string s[N];
int near_[N];
vector<int> g[N], gr[N];
vector<char> used;
vector<int> order, component;
bool no[N];

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i],
        s[i]="_"+s[i];
    auto code=[n,m](int i,int j,bool b=false)->int
    {
        if(i<1||i>n||j<1||j>m&&b)
            return -1;
        return (i-1)*m+(j-1);
    };
    auto add=[code](int i1,int j1,int i2,int j2)->void
    {
        int x=code(i1,j1,true),y=code(i2,j2,true);
        if(x==-1||y==-1)
            return;
        g[code(i1,j1)].push_back(code(i2,j2));
        gr[code(i2,j2)].push_back(code(i1,j1));
    };
    auto near=[code](int i,int j)->int&
    {
        return near_[code(i,j)];
    };
    for(int j=1;j<=m;j++)
        near(n+1,j)=n+1;
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='#')
                near(i,j)=i;
            else
                near(i,j)=near(i+1,j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='#')
            {
                if(i>1&&s[i-1][j]=='#')
                    add(i,j,i-1,j);
                add(i,j,near(i,j-1),j-1);
                add(i,j,near(i,j+1),j+1);
                add(i,j,near(i+1,j),j);
            }

    used.assign (N, false);
    for (int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (!used[code(i,j)]&&s[i][j]=='#')
                dfs1 (code(i,j));
    used.assign (N, false);
    int ans=0;
    reverse(order.begin(),order.end());
    for(int v:order) {
        if (!used[v]) {
            dfs2 (v);
            bool yes=true;
            for(int x:component)
                if(no[x])
                    yes=false;
            for(int x:component)
                for(int to:g[x])
                    no[to]=true;
            ans+=yes;
            component.clear();
        }
    }
    cout<<ans;
}