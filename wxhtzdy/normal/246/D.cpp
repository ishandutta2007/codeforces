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

const int N = 1e5 + 500;
const int M = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int c[N], n, m;
set < int > brt[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", c + i);
	}
	for(int i = 1;i <= m;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(c[x] != c[y]){
			brt[c[x]].insert(c[y]);
			brt[c[y]].insert(c[x]);
		}
	}
	int mx = 1e9;
	for(int i = 1;i <= n;i++){
		mx = min(mx, c[i]);
	}
	for(int i = 1;i < N;i++){
		if(brt[i].size() > brt[mx].size()) mx = i;
	}
	printf("%d", mx);
	return 0;
}