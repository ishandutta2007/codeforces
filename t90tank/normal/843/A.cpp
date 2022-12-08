#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200000; 

int n;
int a[maxn]; 
int no[maxn]; 
bool v[maxn]; 

bool cmp(int x, int y) {
	return a[x] < a[y]; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= n; ++i) no[i] = i; 
	sort(no+1, no+n+1, cmp); 
	vector<vi> ans; 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) {
			int x = i; 
			vi tmp; 
			while (!v[x]) {
				v[x] = true; 
				tmp.pb(x); 
				x = no[x]; 
			}
			ans.pb(tmp); 
		}
	printf( "%d\n", (int)ans.size()); 
	for (auto i : ans) {
		printf( "%d", (int)i.size() ); 
		for (auto j : i) printf( " %d", j ); 
		puts( "" ); 
	}
	return 0;
}