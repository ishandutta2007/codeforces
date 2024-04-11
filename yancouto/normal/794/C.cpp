#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 312345;
char A[N], B[N], s[N];

int main() {
	int i, j;
	scanf("%s %s", A, B);
	n = strlen(A);
	sort(A, A + n);
	sort(B, B + n);
	int lA = 0, rA = ((n + 1) / 2 - 1), lB = (n - (n / 2)), rB = n - 1;
	int l = 0, r = n - 1;
	for(i = 0; i < n; i++) {
		char c;
		if((i & 1) == 0) {
			if(i == n - 1)
				c = s[l++] = A[lA++];
			else if(A[lA] >= B[rB])
				c = s[r--] = A[rA--];
			else
				c = s[l++] = A[lA++];
		} else {
			if(i == n - 1)
				c = s[l++] = B[lB++];
			else if(A[lA] >= B[rB])
				c = s[r--] = B[lB++];
			else
				c = s[l++] = B[rB--];
		}
		//printf("%c plays %c\n", "AB"[i & 1], c);
	}
	assert(l == r + 1 && lA == rA + 1 && lB == rB + 1);
	puts(s);
}