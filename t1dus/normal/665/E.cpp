/*input
5 4
0 1 5 6 7
1
1
4
5
*/
#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define ll long long
#define WL(t) while(t --)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F first
#define S second

#define MX 20000005
 
int n,k,SZ,trie[MX][2],lcnt[MX],rcnt[MX];
string s,good;
 
void insert(int node,int s,int p){
	if(p == -1) return ;
	if(s&(1<<p)){
		rcnt[node] ++;
		if(trie[node][1] == -1) trie[node][1] = ++SZ;
		insert(trie[node][1],s,p-1);
	}
	else{
		lcnt[node] ++;
		if(trie[node][0] == -1) trie[node][0] = ++SZ;
		insert(trie[node][0],s,p-1);
	}
}

int query(int node,int s,int p){
	if(p == -1) return 0;
	int res = 0;
	bool a1 = (s&(1<<p));
	bool a2 = (k&(1<<p));
	// if(p == 0){
	// 	if(a1 and a2) return lcnt[node];
	// 	if(a1) return lcnt[node]+rcnt[node];
	// 	if(a2) return rcnt[node];
	// 	return lcnt[node]+rcnt[node];
	// }
	if(a1 and a2){
		if(trie[node][0] != -1) res += query(trie[node][0],s,p-1);
	}	
	else if(a1){
		res += lcnt[node];
		if(trie[node][1] != -1) res += query(trie[node][1],s,p-1);
	}
	else if(a2){
		if(trie[node][1] != -1) res += query(trie[node][1],s,p-1);
	}
	else{
		res += rcnt[node];
		if(trie[node][0] != -1) res += query(trie[node][0],s,p-1);
	}	
	return res;
}

void solve(){
	SZ = 0;
	REP(i,MX){
		trie[i][0] = trie[i][1] = -1;
		lcnt[i] = 0;
		rcnt[i] = 0;
	}
	cin >> n >> k;
	k --;
	int cur = 0;
	ll ans = 0;
	REP(i,n){
		insert(0,cur,30);
		int x; cin >> x;
		cur ^= x;
		ans = (ll)(ans+query(0,cur,30));
		// cout << ans << endl;
	}
	cout << (ll)ans << endl;
}
 
signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	t = 1;
	while(t --){
		solve();
	}
}