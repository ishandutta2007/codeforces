#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 100009;

int dv[MAX], dvs[MAX][10];

void pre() {
	int i, j;
	for(i = 2; i < MAX; i++) {
		if(dv[i]) continue;
		for(j = i; j < MAX; j += i)
			dv[j] = i;
	}
	for(i = 2; i < MAX; i++) {
		j = 0; int x = i;
		while(x != 1) {
			int k = dv[x];
			dvs[i][j++] = k;
			while(!(x % k)) x /= k;
		}
	}
}
int ac[MAX], ps[MAX];

int main() {
	int i, j, n, m, x; char c;
	pre();
	scanf("%d %d", &n, &m);
	//srand(time(NULL)); rand(); rand();
	for(i = 0; i < m; i++) {
		scanf(" %c %d", &c, &x);
		//c = (rand() & 1)? '+' : '-';
		//x = (rand() % n) + 1;
		if(c == '+') {
			if(ac[x]) {
				puts("Already on");
				continue;
			}
			for(j = 0; dvs[x][j]; j++)
				if(ps[dvs[x][j]])
					break;
			if(dvs[x][j]) { printf("Conflict with %d\n", ps[dvs[x][j]]); continue; }
			puts("Success");
			for(j = 0; dvs[x][j]; j++)
				ps[dvs[x][j]] = x;
		} else {
			if(!ac[x]) {
				puts("Already off");
				continue;
			}
			puts("Success");
			for(j = 0; dvs[x][j]; j++)
				ps[dvs[x][j]] = 0;
		}
		ac[x] = (c == '+');
	}
}