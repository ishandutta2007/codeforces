#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define ll long long
#define WL(t) while(t --)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F first
#define S second
typedef vector <int> vi;
#define pb push_back
#define all(v) v.begin(),v.end()
 
#define MX 2000005
 
int n,SZ;
string a[70005];
unordered_map<int,int> trie[MX]; 
set<int> cont[MX];

void insert(int node,int ind,int p){
	cont[node].insert(ind);
	if(p == 9) return ;
	int z = a[ind][p]-'0';
	if(trie[node].find(z) == trie[node].end()){
		trie[node][z] = ++SZ;
	}
	insert(trie[node][z],ind,p+1);
}
 
int query(int node,int ind,int p){
	if(cont[node].size() == 1) return 0;
	if(p == 9){
		return 10;
	}
	int z = a[ind][p]-'0';
	return query(trie[node][z],ind,p+1)+1;
}
 
void solve(){
	SZ = 0;
	REP(i,MX){
		trie[i].clear();
		cont[i].clear();
	}
	cin >> n;
	int cur = 0,ans = 0;
	REP(i,n){
		cin >> a[i];
		REP(j,9) insert(0,i,j);
	}
	REP(i,n){
		int start = -1,cnt = 10;
		REP(j,9){
			int cur = query(0,i,j);
			if(cur < cnt){
				cnt = cur;
				start = j;
			}
		}
		FOR(j,start,start+max(cnt,1)) cout << a[i][j];
		cout << "\n";
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