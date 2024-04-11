#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<pii> ans;
bool v[26];
vi g[26];
void dfs(int u){
	v[u] = true;
	trav(i,g[u]){
		if(!v[i]){
			ans.pb(mp(i,u));
			dfs(i);
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	string s,t;cin>>s>>t;
	rep(i,n) if(s[i]!=t[i]) {
		g[t[i]-'a'].pb(s[i]-'a');
		g[s[i]-'a'].pb(t[i]-'a');
	}
	rep(i,26) if(!v[i]) dfs(i);
	cout<<sz(ans)<<'\n';
	trav(i,ans){
		cout<<char(i.fst+'a')<<' '<<char(i.snd+'a')<<'\n';
	}
	return 0;
}