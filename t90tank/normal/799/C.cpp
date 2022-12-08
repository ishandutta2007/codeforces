#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200000; 

int N, c[2]; 
int n[2]; 
vector<pair<int,int>> a[2]; 
vector<pair<int,int>> b[2]; 

int main() {
	scanf( "%d%d%d", &N, &c[0],&c[1] ); 
	for (int i = 1; i <= N; ++i) {
		int B, P; 
		char S[10]; 
		scanf( "%d%d%s", &B, &P, S );
		int t; 
		if (S[0] == 'C') t = 0; else t = 1;  
		a[t].pb({P,B});
	}
	int ans = 0; 
	int v[2]; 
	v[0] = v[1] = - 0x3f3f3f3f; 
	for (int i = 0; i <= 1; ++i) {
		sort(a[i].begin(), a[i].end()); 
		for (auto q : a[i]) {
			if (b[i].empty() || q.sec >= b[i].back().sec) b[i].pb(q); 
			else if (q.fir+b[i].back().fir <= c[i]) ans = max(ans,q.sec+b[i].back().sec); 
			if (q.fir <= c[i]) v[i] = max(v[i],q.sec); 
		}
		for (auto q = b[i].begin(); q != b[i].end(); q++) {
			auto u = upper_bound(b[i].begin(),b[i].end(),make_pair(c[i]-q->fir,0x3f3f3f3f)); 
			if (u != b[i].begin() && prev(u) != q) ans = max(ans,q->sec+(prev(u)->sec));
		}
	}
	ans = max(ans, v[0]+v[1]); 
	cout<<ans<<endl; 
}