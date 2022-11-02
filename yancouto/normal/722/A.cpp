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
char h[100];

int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s", h);
	int ct = 0;
	if(h[3] > '5') h[3] = '5';
	if(n == 12) {
		if(h[0] > '1') {
			if(h[1] == '0') h[0] = '1';
			else h[0] = '0';
		} else if(h[0] < '1') {
			if(h[1] == '0') h[1] = '1';
		} else if(h[1] > '2') h[1] = '0';
	} else {
		if(h[0] > '2') h[0] = '0';
		else if(h[0] == '2' && h[1] >= '4') h[1] = '0';
	}
	printf("%s\n", h);
}