#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int M = 8e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int A[N], n, qq;
int val[M][105];
bool psh[M];

void push(int i, bool down){
	if(!psh[i]) return;
	psh[i] = false;
	if(down){
		for(int j = 1;j <= 100;j++){
			val[i * 2][j] = val[i][val[i * 2][j]];
			val[i * 2 + 1][j] = val[i][val[i * 2 + 1][j]];
		}
		psh[i * 2] = true;
		psh[i * 2 + 1] = true;
		for(int j = 1;j <= 100;j++){
			val[i][j] = j;
		}
	}
}

void init(int i, int lo, int hi){
	for(int j = 1;j <= 100;j++){
		val[i][j] = j;
	}
	if(lo == hi) return;
	init(i * 2, lo, (lo + hi) / 2);
	init(i * 2 + 1, (lo + hi) / 2 + 1, hi);
}

void update(int i, int lo, int hi, int a, int b, int x, int y){
	if(a <= lo && hi <= b){
		for(int j = 1;j <= 100;j++){
			if(val[i][j] == x){
				val[i][j] = y;
			}
		}
		psh[i] = true;
		push(i, lo != hi);
		return;
	}
	if(lo > hi || lo > b || hi < a) return;
	push(i, lo != hi);
	update(i * 2, lo, (lo + hi) / 2, a, b, x, y);
	update(i * 2 + 1, (lo + hi) / 2 + 1, hi, a, b, x, y);
}

void resi(int i, int l, int r){
	push(i, l != r);
	if(l == r){
		printf("%d ", val[i][A[l]]); return;
	}
	resi(i * 2, l, (l + r) / 2);
	resi(i * 2 + 1, (l + r) / 2 + 1, r);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", A + i);
	}
	init(1, 1, n);
	scanf("%d", &qq);
	while(qq--){
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		update(1, 1, n, l, r, x, y);
	}
	resi(1, 1, n);
	return 0;
}