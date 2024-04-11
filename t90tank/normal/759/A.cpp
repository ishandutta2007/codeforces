#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000; 

int n; 
int p[maxn]; 
int b[maxn]; 
bool v[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &p[i] );
	int s = 1;  
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &b[i] ); 
		s ^= b[i]; 
	}
	int ans = s; 
	s = 0; 
	memset( v, false, sizeof(v) ); 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) {
			s++; 
			for (int x = i; !v[x]; x = p[x]) 
				v[x] = true;
		} 
	if (s != 1) ans += s; 
	cout<<ans<<endl; 
}