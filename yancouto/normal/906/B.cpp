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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif


int mat[212345];


int n, m;

inline int id(int i, int j) { return i * m + j; }
inline bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, -1, 1};

int main() {
	srand(time(NULL));
	int i, j;
	//while(true) {
	scanf("%d %d", &n, &m);
	//printf("%d %d\n", n, m);
	//n = rand() % 11; m = rand() % 11;
	if(n == 1 && m == 1) {
		//continue;
		printf("YES\n1\n");
		return 0;
	}
	if(n <= 3 && m <= 3) {
		//continue;
		for(i = 0; i < n * m; i++)
			mat[i] = i;
		do {
			bool bad = false;
			for(i = 0; i < n && !bad; i++)
				for(j = 0; j < m && !bad; j++)
					for(int d1 = 0; d1 < 4 && !bad; d1++)
						for(int d2 = 0; d2 < 4 && !bad; d2++) {
							int ni = int(mat[id(i, j)] / m) + di[d2];
							int nj = int(mat[id(i, j)] % m) + dj[d2];
							assert(mat[id(i, j)] == (ni - di[d2]) * m + (nj - dj[d2]));
							if(!valid(i + di[d1], j + dj[d1]) || !valid(ni, nj)) continue;
							if(mat[id(i + di[d1], j + dj[d1])] == id(ni, nj))
								bad = true;
						}
			if(!bad) {
				puts("YES");
				for(i = 0; i < n; i++) {
					for(j = 0; j < m; j++)
						printf("%d ", mat[id(i, j)] + 1);
					putchar('\n');
				}
				return 0;
			}
		} while(next_permutation(mat, mat + (n * m)));
		puts("NO");
		return 0;
	}
	bool sw = false;
	if(m < n) {
		sw = true;
		swap(n, m);
	}
	for(i = 0; i < n; i++) {
		int cj = 0;
		if(i & 1) {
			if(m == 4) {
				for(int j : {2, 0, 3, 1})
					mat[i * m + (cj++)] = i * m + j;
			} else {
				for(j = 0; j < m; j += 2)
					mat[i * m + (cj++)] = i * m + j;
				for(j = 1; j < m; j += 2)
					mat[i * m + (cj++)] = i * m + j;
			}
		} else {
			for(j = 1; j < m; j += 2)
				mat[i * m + (cj++)] = i * m + j;
			for(j = 0; j < m; j += 2)
				mat[i * m + (cj++)] = i * m + j;
		}
	}
	bool bad = false;
	for(i = 0; i < n && !bad; i++)
		for(j = 0; j < m && !bad; j++)
			for(int d1 = 0; d1 < 4 && !bad; d1++)
				for(int d2 = 0; d2 < 4 && !bad; d2++) {
					int ni = int(mat[id(i, j)] / m) + di[d2];
					int nj = int(mat[id(i, j)] % m) + dj[d2];
					assert(mat[id(i, j)] == (ni - di[d2]) * m + (nj - dj[d2]));
					if(!valid(i + di[d1], j + dj[d1]) || !valid(ni, nj)) continue;
					if(mat[id(i + di[d1], j + dj[d1])] == id(ni, nj))
						bad = true;
				}
	assert(!bad);
	if(sw) swap(n, m);
	//continue; 
	puts("YES");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(sw) {
				int x = mat[j * n + i];
				int xi = x / n;
				int xj = x % n;
				printf("%d ", (xj * m + xi) + 1);
			} else printf("%d ", mat[i * m + j] + 1);
		}
		putchar('\n');
	}
	//}
}