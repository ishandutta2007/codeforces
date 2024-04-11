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
vector<vi> ans;
vi g[2];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;cin>>s;
	bool f = false;
	rep(i,sz(s)){
		int x= s[i]-'0';
		if(sz(g[1-x])){
			int y = g[1-x].back();
			g[1-x].pop_back();
			ans[y].pb(i+1);
			g[x].pb(y);
		}
		else if(x==0){
			vi t;t.pb(i+1);
			int y = sz(ans);
			ans.pb(t);
			g[0].pb(y);
		}
		else {
			f=true;break;
		}
	}
	if(f||sz(g[1])) cout<<-1;
	else{
		cout<<sz(ans)<<'\n';
		trav(v,ans){
			cout<<sz(v)<<' ';
			trav(i,v) cout<<i<<' ';
			cout<<'\n';
		}
	}
			

	return 0;
}