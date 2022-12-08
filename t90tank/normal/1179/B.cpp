#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

/*
set<pii> S; 

bool add(int dx, int dy) {
	if (S.find({dx,dy})) return false; 
	S.insert(dx, dy); 
	return true; 
}
*/

int main() {
	int n, m; 
	scanf( "%d%d", &n, &m ); 
	for (int i = 0; 1+i < n-i; ++i) {
		for (int j = 0; j < m; ++j) {
			printf( "%d %d\n", 1+i, 1+j );
			printf( "%d %d\n", n-i, m-j ); 
		}
	}
	if (n & 1) {
		for (int i = 0; 1+i < m-i; ++i) {
			printf( "%d %d\n", n/2+1, 1+i ); 
			printf( "%d %d\n", n/2+1, m-i ); 
		}
		if (m & 1) printf( "%d %d\n", n/2+1, m/2+1 ); 
	}
}