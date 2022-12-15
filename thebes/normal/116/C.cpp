#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define pu push
#define pb push_back
#define em emplace
#define eb emplace_back
#define sp ' '
#define nl '\n'
#define f first
#define s second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t, A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;

const int nax = 2002;
vector<int> adj[nax], dp(nax);
int ans;

int dfs(int src) {
	if(adj[src].empty()) return 1;
	int ret = 0;
	for(int &elm : adj[src]) {
		ret = max(ret, dfs(elm));
	}
	return dp[src] = ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; sc(n);
	for(int i = 1; i <= n; i++) {
		int j; sc(j);
		if(j != -1) adj[j].pb(i);
	}
	for(int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	pr(ans, nl);
}