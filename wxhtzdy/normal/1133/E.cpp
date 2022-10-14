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

const int N = 5e3 + 500;
const int M = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

//:'( :'( :'(

int A[N], B[N], n, k;
int dp[N][N];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", A + i);
	}
	sort(A + 1, A + n + 1);
	for(int i = 1, j = 1;i <= n;i++){
		while(A[i] - A[j] > 5) j++;
		B[i] = j - 1;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++)dp[i][j] = dp[i - 1][j];
		for(int j = 1;j <= k;j++){
			dp[i][j] = max(dp[i][j], dp[B[i]][j - 1] + i - B[i]);
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}