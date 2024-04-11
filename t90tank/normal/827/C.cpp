#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int number(char c) {
	if (c == 'A') return 0; 
	if (c == 'T') return 1; 
	if (c == 'C') return 2; 
	return 3; 
}

#define lowbit(x) ((x)&(-x))
const int maxn = 100006; 
int n, q; 
struct BIT {
	int g[maxn]; 
	void add(int x, int d) {
		for (int i = x; i <= n; i+=lowbit(i)) g[i] += d; 
	}
	int ask(int x) {
		int ans = 0; 
		for (int i = x; i >= 1; i-=lowbit(i)) ans += g[i]; 
		return ans; 
	}
}; 

struct Data {
	BIT num[12][12][4]; 
	void Del(int x, int c) {
		for (int i = 1; i <= 10; ++i) 
			num[i][x%i][c].add(x, -1); 
	}
	void Add(int x, int c) {
		for (int i = 1; i <= 10; ++i) 
			num[i][x%i][c].add(x, 1); 
	}
	int Count(int x, int l, int mod, int c) {
		return num[l][mod][c].ask(x); 
	}
}T; 

char st[maxn];  

int main() {
	scanf( "%s", st+1 ); n = strlen(st+1); 
	for (int i = 1; i <= n; ++i) T.Add(i,number(st[i])); 
	cin>>q; 
	for (int i = 1; i <= q; ++i) {
		int op, l, r, x; 
		char s[20]; 
		scanf( "%d", &op ); 
		if (op == 1) {
			scanf( "%d%s", &x, s ); 
			T.Del(x,number(st[x])); 
			st[x] = s[0]; 
			T.Add(x,number(st[x])); 
		}
		else {
			scanf( "%d%d%s", &l, &r, s ); 
			int len = strlen(s); 
			int ans = 0; 
			for (int i = l; i <= r && i < l+len; ++i) {
				ans += T.Count(r,len,i%len,number(s[i-l]))-T.Count(l-1,len,i%len,number(s[i-l])); 
				//printf( "%d-%d\n", T.Count(r,len,i%len,number(s[i-l])),T.Count(l-1,len,i%len,number(s[i-l]))); 
			}
			printf( "%d\n", ans );
		}
	}
}