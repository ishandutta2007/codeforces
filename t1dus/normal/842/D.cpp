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
 
#define MX 4000005
 
int n,q,SZ,trie[MX][2],a[300005];
bool isthere[600005];
 
void insert(int node,int s,int p){
	if(p == -1) return;
	if(s&(1<<p)){
		if(trie[node][1] == -1) trie[node][1] = ++SZ;
		insert(trie[node][1],s,p-1);
	}
	else{
		if(trie[node][0] == -1) trie[node][0] = ++SZ;
		insert(trie[node][0],s,p-1);
	}
}

/*
we want a number y such that s^y is the smallest
if the pth bit is set in s then we want it set in y
else we don't want it set in y
*/

int query(int node,int s,int p){
	if(p == -1) return 0;
	if(s&(1<<p)){
		if(trie[node][1] == -1){
			return (1<<p)+query(trie[node][0],s,p-1);
		}
		return query(trie[node][1],s,p-1);
	}
	else{
		if(trie[node][0] == -1){
			return (1<<p)+query(trie[node][1],s,p-1);
		}
		return query(trie[node][0],s,p-1);
	}
}

void solve(){
	SZ = 0;
	REP(i,MX){
		trie[i][0] = trie[i][1] = -1;
	}
	cin >> n >> q;
	REP(i,(1<<19)) isthere[i] = false;
	REP(i,n) cin >> a[i],isthere[a[i]] = true;
	REP(i,(1<<19)){
		if(!isthere[i]) insert(0,i,20);
	}
	int cur = 0;
	WL(q){
		int x; cin >> x;
		cur ^= x;
		cout <<	query(0,cur,20) << "\n";
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