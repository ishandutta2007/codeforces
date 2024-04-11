#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

vector<int> q; 
set<pair<int,int>> S[20]; 
int n, k; 
int a[100000][20]; 
bool v[3000000]; 
int dic[600000][12]; 
int mind[20]; 
int maxd[20]; 

int main() {
	scanf( "%d%d", &n, &k ); 
	int ans = 0; 
	for (int j = 0; j < k; ++j) {
		maxd[j] = 0; 
		mind[j] = 0; 
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j) 
			scanf( "%d", &a[i][j] ); 
		bool flag = true; 
		for (int j = 0; j < k; ++j) 
			flag &= (a[i][j] >= maxd[j]); 
		if (flag) {
			v[q.size()] = true; 
			for (int j = 0; j < k; ++j) 
				dic[q.size()][j] = mind[j]; 
			q.pb(ans); 
			for (int j = 0; j < k; ++j) 
				S[j].insert( {-maxd[j], (int)q.size()-1} ); 
			for (int j = 0; j < k; ++j) 
				mind[j] = maxd[j] = a[i][j]; 
			ans = 1; 
		}
		else {
			//flag = false; 
			//for (int j = 0; j < k; ++j) 
				//flag |= (a[i][j] >= mind[j]); 
			//if (flag) {
				//for (int j = 0; j < k; ++j) 
					//mind[j] = min(mind[j], a[i][j]); 
			//}
			v[q.size()] = true; 
			for (int j = 0; j < k; ++j) 
				dic[q.size()][j] = a[i][j]; 
			q.pb(1); 
			//cout<<q.size()<<endl; 
			for (int j = 0; j < k; ++j) 
				S[j].insert( {-a[i][j], (int)q.size()-1} );  
			bool tag = true; 
			while (tag) { 
				tag = false; 
				for (int j = 0; j < k; ++j) 
					while (!S[j].empty() && -(S[j].begin())->fir >= mind[j]) {
						auto u = S[j].begin(); 
						if (v[u->sec]) {
							//cout<<u->fir<<'+'<<u->sec<<' '; 
							v[u->sec] = false; 
							ans += q[u->sec]; 
							for (int j = 0; j < k; ++j) 
								mind[j] = min(mind[j], dic[u->sec][j]); 
						}
						tag = true; 
						S[j].erase(u); 
					}
			}
		}
		for (int j = 0; j < k; ++j) 
			maxd[j] = max(maxd[j], a[i][j]); 
		printf( "%d\n", ans ); 
	}
	return 0;
}