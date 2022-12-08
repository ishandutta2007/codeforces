#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

bool Ask(int x) {
	printf( "1 %d %d\n", x, x+1 ); 
	fflush(stdout); 
	char st[10]; 
	scanf( "%s", st ); 
	return (st[0]  == 'T'); 
}

bool Ask2(int x, int y) {
	printf( "1 %d %d\n", x, y ); 
	fflush(stdout); 
	char st[10]; 
	scanf( "%s", st ); 
	return (st[0]  == 'T'); 
}

int solve(int l, int r) {
	if (l > r) return 0; 
	if (l == r) return l; 
	int m = (l+r) / 2; 
	if (Ask(m)) return solve(l,m); 
	else return solve(m+1,r); 
}

int n, k; 

int main() {
	scanf("%d%d", &n, &k ); 
	int x = solve(1, n); 
	int y1 = solve(1,x-1); 
	int y2 = solve(x+1,n); 
	if (y1 != 0 && Ask2(y1,x)) printf("2 %d %d\n", y1, x); 
	else printf( "2 %d %d\n", x, y2 ); 
	fflush(stdout); 
	return 0;
}