#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const int D = 2006; 

int k, n; 
vector<int> a; 
int f[D+10]; 

int main() {
	scanf( "%d%d", &k, &n ); 
	set<int> S; 
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf( "%d", &x ); 
		x -= k; 
		if (S.find(x) == S.end()) {
			S.insert(x); 
			a.pb(x); 
		}
	}
	fill(f, f+D+1, -1); 
	deque<int> Q; 
	for (auto i : a)  
		if (i >= 0) {
			f[i] = 1; 
			Q.pb(i); 
		}
	while (!Q.empty()) {
		auto u = Q.front();
		Q.pop_front();
		//cout<<u<<endl;  
		for (auto i : a) {
			int v = u+i; 
			//cout<<v<<endl; 
			if (v >= 0 && v < D && f[v] == -1) {
				f[v] = f[u]+1; 
				Q.pb(v); 
			}
		}
	}
	cout<<f[0]<<endl; 
}