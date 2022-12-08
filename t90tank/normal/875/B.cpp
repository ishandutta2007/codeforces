#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

set<int> S; 
int n, m; 

int main() {
	scanf( "%d", &n ); 
	m = n; 
	printf( "1" ); 
	for (int i = 1; i <= n; ++i) {
		int p; 
		scanf( "%d", &p ); 
		S.insert( p ); 
		while (!S.empty() && *S.rbegin() == m) {
			S.erase(m); 
			m--; 
		}
		printf( " %d", (int)S.size() + 1 ); 
	}
	puts( "" ); 
}