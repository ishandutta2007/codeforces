#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

#define pos(x,y) ((x)*m+(y))
#define posr(x,y) ((y)*m+(x))

int a[5000000]; 
int n, m; 
int b[5000000]; 
int ans[5000000]; 
char s[5000000]; 
int tot; 
int anssum = -1; 

int main() {
	scanf( "%d%d", &n, &m ); 
	tot = n * m; 
	for (int i = 0; i < n; ++i) {
		scanf( "%s", s ); 
		for (int j = 0; j < m; ++j) {
			int x; 
			if (s[j] == 'A') x = 0; 
			else if (s[j] == 'G') x = 1; 
			else if (s[j] == 'C') x = 2; 
			else x = 3; 
			a[pos(i,j)] = x; 
		}
	}
	for (b[0] = 0; b[0] < 4; ++b[0]) 
	for (b[1] = 0; b[1] < 4; ++b[1])
	if (b[1] != b[0])
	for (b[m] = 0; b[m] < 4; ++b[m])
	if (b[m] != b[1] && b[m] != b[0]) {
		b[m+1] = 6-b[0]-b[1]-b[m]; 
		for (int i = 2; i < m; ++i) {
			b[pos(0,i)] = b[pos(0,i%2)]; 
			b[pos(1,i)] = b[pos(1,i%2)]; 
		}
		for (int i = 2; i < n; ++i) {
			int s = 0; 
			for (int j = 0; j < m; ++j) {
				if (a[pos(i,j)] == b[pos(i%2,j%2)]) s++; 
				if (a[pos(i,j)] == b[pos(i%2,1-j%2)]) s--; 
			}
			if (s >= 0) 
				for (int j = 0; j < m; ++j) b[pos(i,j)] = b[pos(i%2,j%2)]; 
			else for (int j = 0; j < m; ++j) b[pos(i,j)] = b[pos(i%2,1-j%2)]; 
		}
		int sum = 0; 
		for (int i = 0; i < tot; ++i) sum += (a[i] == b[i]); 
		if (sum > anssum) {
			anssum = sum; 
			for (int i = 0; i < tot; ++i) ans[i] = b[i]; 
		}
		for (int i = 2; i < n; ++i) {
			b[posr(0,i)] = b[posr(0,i%2)]; 
			b[posr(1,i)] = b[posr(1,i%2)]; 
		}
		for (int i = 2; i < m; ++i) {
			int s = 0; 
			for (int j = 0; j < n; ++j) {
				if (a[posr(i,j)] == b[posr(i%2,j%2)]) s++; 
				if (a[posr(i,j)] == b[posr(i%2,1-j%2)]) s--; 
			}
			if (s >= 0) 
				for (int j = 0; j < n; ++j) b[posr(i,j)] = b[posr(i%2,j%2)]; 
			else for (int j = 0; j < n; ++j) b[posr(i,j)] = b[posr(i%2,1-j%2)]; 
		}
		sum = 0; 
		for (int i = 0; i < tot; ++i) sum += (a[i] == b[i]); 
		if (sum > anssum) {
			anssum = sum; 
			for (int i = 0; i < tot; ++i) ans[i] = b[i]; 
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ans[pos(i,j)] == 0) printf( "A" ); 
			else if (ans[pos(i,j)] == 1) printf( "G" ); 
			else if (ans[pos(i,j)] == 2) printf( "C" ); 
			else if (ans[pos(i,j)] == 3) printf( "T" ); 
		}
		puts( "" ); 
	}
}