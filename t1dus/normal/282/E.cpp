/*input
2
1000 1000
*/
#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define ll long long
#define int ll
#define WL(t) while(t --)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F first
#define S second

#define MX 4000005
 
int n,k,SZ,trie[MX][2],lcnt[MX],rcnt[MX],a[100005],power[50];

void insert(int node,int s,int p){
	if(p == -1) return ;
	if(s&(power[p])){
		if(trie[node][1] == -1) trie[node][1] = ++SZ;
		insert(trie[node][1],s,p-1);
	}
	else{
		if(trie[node][0] == -1) trie[node][0] = ++SZ;
		insert(trie[node][0],s,p-1);
	}
}

int query(int node,int s,int p){
	if(p == -1) return 0;
	if(s&(power[p])){
		if(trie[node][0] == -1){
			return (query(trie[node][1],s,p-1));
		}
		return (power[p]+query(trie[node][0],s,p-1));
	}
	else{
		if(trie[node][1] == -1){
			return (query(trie[node][0],s,p-1));
		}
		return (power[p]+query(trie[node][1],s,p-1));
	}
}

void solve(){
	SZ = 0;
	REP(i,MX){
		trie[i][0] = trie[i][1] = -1;
	}
	cin >> n;
	int cur = 0,cur2 = 0;
	REP(i,n){
		cin >> a[i];
		cur ^= a[i];
	}
	int ans = cur;
	power[0] = 1;
	FOR(i,1,50) power[i] = (2*power[i-1]);
	insert(0,0,40);
	REP(i,n){
		cur ^= a[i];
		cur2 ^= a[i];
		insert(0,cur2,40);
		ans = max(ans,query(0,cur,40));
	}
	cout << ans << endl;
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