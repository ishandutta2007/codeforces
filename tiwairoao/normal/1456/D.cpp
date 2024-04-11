#include <bits/stdc++.h>

typedef long long ll;

const int N = 5000;

ll t[N + 5], x[N + 5]; int n;

bool a[N + 5]; ll b[N + 5];
void update(ll l, ll r, int i) {
	if( l <= x[i] && x[i] <= r )
		b[i] = std::max(b[i], t[i] - t[i - 1]);
	else if( x[i] < l )
		b[i] = std::max(b[i], t[i] - t[i - 1] - (l - x[i]));
	else
		b[i] = std::max(b[i], t[i] - t[i - 1] - (x[i] - r));
}
ll mabs(ll k) {return k >= 0 ? k : -k;}
void update2(ll l, ll r, int j, int i) {
	if( l <= x[i] && x[i] <= r )
		a[i] |= (t[j] - t[j - 1] >= mabs(x[j] - x[i]));
	else if( x[i] < l )
		a[i] |= (t[j] - t[j - 1] - (l - x[i]) >= mabs(x[j] - x[i]));
	else 
		a[i] |= (t[j] - t[j - 1] - (x[i] - r) >= mabs(x[j] - x[i]));
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld%lld", &t[i], &x[i]);
	
	a[0] = false, b[0] = 0;
	for(int i=1;i<=n;i++) {
		b[i] = -1;
		if( a[i - 1] )
			update(x[i - 2] - (t[i - 1] - t[i - 2]), x[i - 2] + (t[i - 1] - t[i - 2]), i);
		if( b[i - 1] >= 0 )
			update(x[i - 1] - b[i - 1], x[i - 1] + b[i - 1], i);
		
		for(int j=i-1;j>=1;j--) {
			if( a[j - 1] )
				update2(x[j - 2] - (t[j - 1] - t[j - 2]), x[j - 2] + (t[j - 1] - t[j - 2]), j, i);
			if( b[j - 1] >= 0 )
				update2(x[j - 1] - b[j - 1], x[j - 1] + b[j - 1], j, i);
			if( (t[j] - t[j - 1]) < mabs(x[j] - x[j - 1]) ) break;
		}
		
		if( b[i] < 0 && !a[i] ) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}