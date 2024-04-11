#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        g.resize(n);
        gr.resize(n);
        for(int i=0;i<n;i++)
            gr[i].clear(),g[i].clear();
        while(m--) {
            int a, b;
            cin>>a>>b;
            a--,b--;
            gr[a].push_back (b);
            g[b].push_back (a);
        }

        used.assign (n, false);
        order.clear();
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);
        used.assign (n, false);
        component.clear();
        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                if(component.size()==n)
                    cout<<"No\n";
                else
                {
                    cout<<"Yes\n";
                    cout<<component.size()<<" "<<n-component.size()<<"\n";
                    set<int> s;
                    for(int i=0;i<n;i++)
                        s.insert(i);
                    for(int x:component)
                        cout<<x+1<<" ",
                        s.erase(x);
                    cout<<"\n";
                    for(int x:s)
                        cout<<x+1<<" ";
                    cout<<"\n";
                }
                component.clear();
                break;
            }
        }
    }
}