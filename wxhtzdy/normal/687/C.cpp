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

const int N = 550;
const int M = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int A[N], n, k;
bool dp[N][N][N];

int main(){
        scanf("%d%d", &n, &k);
        for(int i = 1;i <= n;i++){
                scanf("%d", A + i);
        }
        dp[0][0][0] = true;
        for(int i = 1;i <= n;i++){
                for(int x = 0;x <= k;x++){
                        for(int y = 0;y <= k;y++){
                                dp[i][x][y] = dp[i - 1][x][y];
                                if(x >= A[i]) dp[i][x][y] = dp[i][x][y] | dp[i - 1][x - A[i]][y];
                                if(x >= A[i] && y >= A[i]) dp[i][x][y] = dp[i][x][y] | dp[i - 1][x - A[i]][y - A[i]];
                        }
                }
        }
        vi ans;
        for(int i = 0;i <= k;i++){
                if(dp[n][k][i]){
                        ans.PB(i);
                }
        }
        printf("%d\n", ans.size());
        for(int i : ans){
                printf("%d ", i);
        }
	return 0;
}