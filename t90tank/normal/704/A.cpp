#include <bits/stdc++.h>
using namespace std; 

const int maxn = 300001; 

deque<int> a[maxn]; 
deque<int> A; 
bool v[maxn]; 
int T; 

int main() {
	int n, q; 
	scanf( "%d%d", &n, &q ); 
	int tot = 0, T = 0; 
	for (int i = 1; i <= q; ++i) {
		int op, x; 
		scanf( "%d%d", &op, &x ); 
		if ( op == 1 ) {
			++T; 
			a[x].push_back( T ); 
			A.push_back( T ); 
			tot++; 
		}
		else if ( op == 2 ) {
			while ( !a[x].empty() ) {
				int u = a[x].front(); 
				if ( !v[u] ) {
					v[u] = true; 
					tot--; 
				}
				a[x].pop_front(); 
			}
		}
		else {
			while ( (!A.empty()) && (A.front()<=x) ) {
				int u = A.front(); 
				if ( !v[u] ) {
					v[u] = true; 
					tot--; 
				}
				A.pop_front(); 
			}
		}
		printf( "%d\n", tot ); 
	}
}