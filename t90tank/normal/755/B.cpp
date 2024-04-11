#include <bits/stdc++.h>
using namespace std;

int n, m; 
int a[4]; 
map<string,int> D; 
char st[10000]; 

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%s", st ); 
		string S = st; 
		D[st] += 1; 
	}
	for (int i = 1; i <= m; ++i) {
		scanf( "%s", st ); 
		string S = st; 
		D[st] += 2; 
	}
	for (auto d : D) a[d.second]++; 
	if ((a[3]+1)/2+a[1] > a[3]/2 +a[2]) printf( "YES\n" ); 
	else printf( "NO\n" ); 
}