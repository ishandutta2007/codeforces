#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
 
#define LL long long
#define mp make_pair
#define pb push_back
 
#define K 600001
 
string x;
 
int n, a[K];
 
vector<int> p;
 
int solve(int space) {
	p.clear();
	
	if (space == n) return 1;

	int i = space - 1;
	
//	printf("space = %d\n", space);
	
	while (i != n) {
		if (a[i + 1] != 0 || i + 1 == n) {
			return -1; 
		} else {
			i++;	
		}
		
		if (a[i + 1] == 0) {
			int ptr = i + 1;
			while (a[ptr] == 0 && ptr <= n) ptr++;
 
			int len = ptr - i - 1;
			
			if (ptr <= n) len--;
			if (len == 0) return -1; 
			
			if (space == 0) {
				return -1; 
			}
			
			if (space == 1 && (len % 2 == 0)) {
				return -1; 
			}
			
			while (len) {
				if (len <= 2) {
					p.pb(len);
					len = 0;	
				} else {
					p.pb(1);
					len -= 2;
				}
			}
			
			if (ptr <= n) i = ptr - 2;
			else i = n;
			
		} else {
			int ptr = i + 1;
			while (ptr <= n && a[ptr] == 1) ptr++;
			int len = ptr - i - 1; 
			
			p.pb(len + space);
			
			i = ptr - 1;
 
			FOE(j, i + 1, i + space) if (j > n || a[j] == 1) {
				return -1; 
			}
			
			i += space;
		}
	}
	
	return 1;
}
 
int main() {
	cin >> x;
	n = x.length();
	
	FOE(i, 1, n) a[i] = (x[i - 1] == '_' ? 0 : 1);
	int cnt = 0, best = n + n;
	int flag = 0;
	
	FOE(i, 1, n) {
		if (a[i] == 0) {
			cnt++;
		} else if (cnt) {
			best = min(best, cnt - flag);
			cnt = 0;
			flag = 1;	
		}
	}
	
	best = min(best, cnt);
	best = min(best, 4);
	
	FOE(i, 0, best) if (i >= 0) {
		int res = solve(i);
		if (res != -1) {
			printf("%d\n", p.size());
			
			for (auto x : p) printf("%d ", x);
			puts("");
			return 0;
			
		} 
	}
		puts("-1");	
	
}