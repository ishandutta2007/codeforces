/*input
1 2
ab
*/		
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define MX 200005
#define M2 55

int n,k,lose[MX],win[MX],SZ = 0;
unordered_map<int,int> trie[MX];
bool isleaf[MX];
string a[MX];

void solve(int node){
	if(isleaf[node]){
		win[node] = false;
		lose[node] = true;
		return ;
	}
	win[node] = false;
	lose[node] = false;
	for(auto i:trie[node]){
		int u = i.second;
		if(u == -1) continue;
		solve(u);
		if(!win[u]) win[node] = true;
		if(!lose[u]) lose[node] = true;
	}
}

void insert(int node,int s,int p){
	if(p == a[s].length()) return ;
	isleaf[node] = false;
	int z = a[s][p]-'a';
	if(trie[node].find(z) == trie[node].end()){
		trie[node][a[s][p]-'a'] = ++SZ;
		insert(SZ,s,p+1);
	}
	else{
		insert(trie[node][a[s][p]-'a'],s,p+1);
	}
}

void solve(){
	SZ = 0;
	REP(i,MX){
		lose[i] = -1;
		win[i] = -1;
		isleaf[i] = true;
		trie[i].clear();
	}
	cin >> n >> k;
	REP(i,n){
		cin >> a[i];
		insert(0,i,0);
	}
	solve(0);
	if(!win[0]){
		cout << "Second\n";
	}
	else if(lose[0]){
		cout << "First\n";
	}
	else{
		if(k%2 == 1) cout << "First\n";
		else cout << "Second\n";
	}
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