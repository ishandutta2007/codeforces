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
 
#define int long long
#define INF 1000000000
#define WL(t) while(t --)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F first
#define S second

#define MX 3000005
 
int n,k,SZ;
unordered_map<int,int> trie[MX];
string s,good;
 
void insert(int node,int p){
	if(p == n) return ;
	int z = s[p]-'a';
	if(trie[node].find(z) == trie[node].end()){
		trie[node][z] = ++SZ;
	}
	insert(trie[node][z],p+1);
}

int query(int node,int cnt){
	int res = 1;
	for(auto it = trie[node].begin(); it != trie[node].end(); it++){
		// cout << it->F << " " << it->S << endl;
		if(good[it->F] == '1'){
			res += query(it->S,cnt);
		}
		else{
			if(cnt != k) res += query(it->S,cnt+1); 
		}
	}
	return res;
}

void solve(){
	SZ = 0;
	REP(i,MX){
		trie[i].clear();
	}
	cin >> s >> good >> k;
	// cout << s << " " << good << " " << k << endl;
	n = s.length();
	REP(i,n){
		insert(0,i);
	}
	cout << query(0,0)-1 << endl;
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