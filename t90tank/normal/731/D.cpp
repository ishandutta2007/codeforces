#include <bits/stdc++.h>
using namespace std; 

const int maxn = 550000; 
vector<int> w[maxn]; 
int n, c; 
int add[maxn*2]; 

int main() {
	scanf( "%d%d", &n, &c ); 
	for (int i = 1; i <= n; ++i) {
		int l;
		scanf( "%d", &l ); 
		for (int j = 0; j < l; ++j) {
			int x; 
			scanf( "%d", &x ); 
			x--; 
			w[i].push_back( x ); 
		}
	}
	bool poss = true; 
	int all = 0; 
	for (int i = 1; i < n; ++i) {
		bool flag = true; 
		for (int j = 0; j < min( w[i].size(), w[i+1].size() ); ++j)
			if ( w[i][j] != w[i+1][j] ) {
				if (w[i][j] < w[i+1][j]) {
					add[0]++; 
					add[c-w[i+1][j]]--; 
					add[c-w[i][j]]++;
	//				add[2*c-w[i][j]]--; 
				}
				else {
					add[c-w[i][j]]++; 
					add[c-w[i+1][j]]--; 
	//				add[2*c-w[i][j]]++; 
	//				add[2*c-w[i+1][j]]--; 
				}
				flag = false; 
				all++; 
				break; 
			}
		if ( flag ) if (w[i].size() > w[i+1].size()) {
			poss = false; 
			break; 
		}
	}		
	int tmp = 0; 
	int ans = -1; 
	for (int i = 0; i < c; ++i) {
		tmp += add[i];  
		if ( tmp == all ) {
			ans = i; 
			break; 
		}
	}
	if ( poss && ans != -1 ) printf( "%d\n", ans ); 
	else printf( "-1\n" ); 
}