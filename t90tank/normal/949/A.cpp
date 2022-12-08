#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

vector<int> q[2]; 
char s[300000]; 
int a[300000]; 
int nxt[300000]; 
bool v[300000]; 
vector<vi> ans; 

int main() {
	scanf( "%s", s+1 ); 
	int n = strlen(s+1); 
	for (int i = 1; i <= n; ++i) 
		a[i] = s[i] - '0'; 
	q[0].clear(); q[1].clear(); 
	memset(nxt, 0, sizeof(nxt)); 
	for (int i = 1; i <= n; ++i) 
		if (a[i]) { 
			if (q[0].empty()) {
				puts( "-1" ); 
				return 0; 
			}
			else {
				nxt[q[0].back()] = i; 
				q[0].pop_back(); 
				q[1].pb(i); 
			}
		}
		else {
			if (q[1].empty()) q[0].pb(i); 
			else {
				nxt[q[1].back()] = i; 
				q[1].pop_back(); 
				q[0].pb(i); 
			}	
		}
	if (!q[1].empty()) {
		puts( "-1" ); 
		return 0; 
	}
	memset(v, false, sizeof(v)); 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) {
			ans.pb(vector<int>(0)); 
			for (int j = i; j; j = nxt[j]) {
				v[j] = true; 
				ans.back().pb(j); 
			}
		}
	printf( "%d\n", (int)ans.size()); 
	for (auto i : ans) {
		printf( "%d", (int)i.size()); 
		for (auto j : i) printf( " %d", j ); 
		puts( "" ); 
	}
	return 0;
}