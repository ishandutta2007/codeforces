#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define pb push_back
#define pii pair<int,int>
#define xx first
#define yy second

using namespace std;

int n,m,q;

vector<int> graf[300005];

int cnt[300005];
pii kveri[300005];

bool vis[300005];
int cale[300005];
int disc[300005];
int out[300005];
int t;
void dfs(int u){
	vis[u] = true;
	disc[u] = t;
	for(int c:graf[u]){
		if(vis[c])continue;
		t++;
		cale[c] = u;
		dfs(c);
	}
	out[u] = t;
}

bool anc(int x, int y){return disc[x] <= disc[y] && out[y] <= out[x];}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ff(i,1,m){
		int u,v;
		cin >> u >> v;
		graf[u].pb(v);
		graf[v].pb(u);
	}
	dfs(1);
	cin >> q;
	ff(i,1,q){
		cin >> kveri[i].xx >> kveri[i].yy;
		cnt[kveri[i].xx]++;
		cnt[kveri[i].yy]++;
	}
	int s = 0;
	ff(i,1,n)s += (cnt[i]&1);
	if(s){
		cout << "NO\n" << s/2;
		return 0;
	}
	cout << "YES\n";
	ff(i,1,q){
		int a = kveri[i].xx;
		int b = kveri[i].yy;
		vector<int> r;
		while(!anc(a, b)){
			r.pb(a);
			a = cale[a];
		}
		r.pb(a);
		vector<int> l;
		while(b != a){
			l.pb(b);
			b = cale[b];
		}
		reverse(l.begin(), l.end());
		vector<int> ans;
		for(int c:r)ans.pb(c);
		for(int c:l)ans.pb(c);
		cout << ans.size() << "\n";
		for(int c:ans)cout << c << " ";
		cout << "\n";
	}
	return 0;
}