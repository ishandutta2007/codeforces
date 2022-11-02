#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }

const int MAX = 1300000;
int dv[MAX];
void pre() {
	for(int i = 2; i < MAX; i++) {
		if(dv[i]) continue;
		for(int j = 2*i; j < MAX; j += i)
			dv[j] = 1;
	}
	for(int i = 2; i < MAX; i++) {
		dv[i] = !dv[i];
		dv[i] += dv[i - 1];
	}
}

int pal[MAX];

bool pall(int x) {
	char str[20]; memset(str, 0, sizeof str);
	sprintf(str, "%d", x);
	int l = strlen(str);
	for(int i = 0; i < l; i++)
		if(str[i] != str[l - i - 1])
			return false;
	return true;
}


void pre2() {
	for(int i = 1; i < MAX; i++) {
		pal[i] = pall(i);
		pal[i] += pal[i - 1];
	}
}

int main() {
	int p, q, i;
	pre();
	pre2();
	//for(i = 1; i < MAX; i++)
	//	printf("%d ->  %f\n", i, double(dv[i]) / pal[i]);
	scanf("%d %d", &p, &q);
	for(i = MAX - 1; i >= 1; i--) {
		if(q * dv[i] <= p * pal[i])
			break;
	}
	if(i == 0) puts("Palindromic tree is better than splay tree");
	else printf("%d\n", i);
	return 0;
}