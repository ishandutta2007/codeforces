/*input
1
z
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

#define MX 100005

int n;
vi adj[MX];
bitset<MX> to,vis,seen;
bool can = true;
string alph = "abcdefghijklmnopqrstuvwxyz";

string dfs(int u){
	// cout << u << "-----------\n";
	if(vis[u] or adj[u].size() > 1){
		can = false;
		return "";
	}
	vis[u] = 1;
	string lol = "-";
	lol[0] = alph[u];
	// cout << u << " ---------------- " << lol << endl;
	// if(adj[u].size()) cout << adj[u][0] << endl;
	if(adj[u].size() == 0) return lol;
	return lol+dfs(adj[u][0]);
}	

bool check(string s,int l){
	int cnt[26];
	fill(cnt,cnt+26,0);
	REP(i,l){
		cnt[s[i]-'a'] ++;
		seen[s[i]-'a'] = 1;
	}
	REP(i,26){
		if(cnt[i] > 1) return false;
	}
	return true;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n){
		string s; cin >> s;
		int l = s.length();
		if(l > 26 or (!check(s,l))){
			cout << "NO\n";
			return 0;
		}
		FOR(j,1,l){
			to[s[j]-'a'] = 1;
			if(adj[s[j-1]-'a'].size() == 0) adj[s[j-1]-'a'].pb(s[j]-'a');
			else if(adj[s[j-1]-'a'][0] != s[j]-'a'){
				cout << "NO\n";
				return 0;
			}
		}
	}
	string ans = "";
	REP(i,26){
		if(seen[i] and (!vis[i]) and (!to[i])) ans += dfs(i);
	}
	if(ans == "") can = false;
	REP(i,n){
		if(seen[i] and (!vis[i])) can = false;
	}
	if(!can) cout << "NO";
	else cout << ans;
}