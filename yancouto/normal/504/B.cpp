#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 212345 * 4;

int b1[N], b2[N], p[N], q[N];
int n;

//void add(int b[], int i, int v) {
//	for(i += 2; i < N; i += (i & -i))
//		b[i] += v;
//}

void add(int b[], int ind, int l, int r, int i, int v) {
	if(l == r) return (void) (b[ind] += v);
	int m = (l + r) / 2;
	if(i <= m) add(b, 2*ind, l, m, i, v);
	else add(b, 2*ind+1, m + 1, r, i, v);
	b[ind] = b[2*ind] + b[2*ind + 1];
}

void add(int b[], int i, int v) { add(b, 1, 0, n - 1, i, v); }

//int query(int b[], int i) {
//	int sum = 0;
//	for(i += 2; i; i -= (i & -i))
//		sum += b[i];
//	return sum;
//}

int query(int b[], int ind, int l, int r, int i) {
	if(l > i) return 0;
	if(r <= i) return b[ind];
	int m = (l + r) / 2;
	return query(b, 2*ind, l, m, i) + query(b, 2*ind + 1, m + 1, r, i);
}

int query(int b[], int i) { return query(b, 1, 0, n - 1, i); }


int search(int b[], int i, int l, int r, int val) {
	if(l == r) return l;
	int m = (l + r) / 2;
	if(b[2*i] >= val) return search(b, 2*i, l, m, val);
	else return search(b, 2*i+1, m + 1, r, val - b[2*i]);
}

int num[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &q[i]);
	for(i = 0; i < n; i++)
		add(b1, i, 1), add(b2, i, 1);
	for(i = 0; i < n; i++) {
		int vp = query(b1, p[i]) - 1, vq = query(b2, q[i]) - 1;
		add(b1, p[i], -1); add(b2, q[i], -1);
		num[i] = vp + vq;
	}
	int carry = 0;
	for(i = n - 1; i >= 0; i--) {
		num[i] += carry;
		carry = num[i] / (n - i);
		num[i] %= n - i;
	}
	for(i = 0; i < n; i++) add(b1, i, 1);
	for(i = 0; i < n; i++) {
		int v = search(b1, 1, 0, n - 1, num[i] + 1);
		add(b1, v, -1);
		//puts("=====");
		//for(j = 0; j < n; j++)
		//	printf("%d ", query(b1, j) - query(b1, j - 1));
		//puts("=====");
		printf("%d ", v);
	}
	putchar('\n');
	
}