#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 

int n, d, b; 
int a[maxn]; 

int Abs(int x) {
	return max(x, -x); 
}

bool solve(int x) {
	int no = x + 1, num = 0; 
	for (int i = 1; i <= n; ++i) {
		int s = a[i]; 
		while (s > 0 && (Abs(no-i)+d-1)/d <= min(no,n-no+1)) {
			int r = min(s, b-num); 
			s -= r; 
			num += r; 
			if (num == b) {
				no++; 
				num = 0; 
			}
		}
	}
	if (no > n-x) return true; 
	return false; 	
}

int main() {
	scanf( "%d%d%d", &n, &d, &b ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	int l = -1, r = n / 2 + 1; 
	while (l + 1 < r) {
		int m = (l + r) / 2; 
		if (solve(m)) r = m; 
		else l = m; 
	}
	printf( "%d\n", r ); 
}