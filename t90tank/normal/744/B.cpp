#include <bits/stdc++.h>
using namespace std; 

const int maxn = 2000; 
const int oo = 0x3f3f3f3f; 
using ll = long long; 

int n; 
int a[30][maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 0; i <= 20; ++i) 
		for (int j = 0; j <= n; ++j) 
			a[i][j] = oo; 
	for (int i = 0; i < 10; ++i) 
		for (int j = 0; j <= 1; ++j) {
			vector<int> Q; 
			for (int k = 0; k < n; ++k) 
				if (((k>>i)&1) != j) Q.push_back(k+1); 
			if (!Q.empty()) {
				printf( "%d\n", (int)Q.size() ); 
				for (auto x : Q) printf( "%d ", x ); 
				printf( "\n" ); 
				fflush(stdout); 
				for (int k = 0; k < n; ++k) scanf( "%d", &a[i*2+j][k] ); 
			}
		}
	printf( "-1\n" ); 
	for (int i = 0; i < n; ++i) {
		int ans = oo; 
		for (int j = 0; j < 10; ++j) 
			ans = min(ans,a[j*2+((i>>j)&1)][i] ); 
		printf( "%d ", ans ); 
	}
	printf( "\n" ); 
}