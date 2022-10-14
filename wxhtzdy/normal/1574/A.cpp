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

void solve(){
        int n;
        scanf("%d", &n);
        for(int turn = 1;turn <= n;turn++){
                for(int i = 1;i <= turn;i++){
                        printf("(");
                }
                for(int i = 1;i <= turn;i++){
                        printf(")");
                }
                int x = 1;
                for(int i = 2 * turn + 1;i <= 2 * n;i++){
                        if(x) printf("(");
                        else printf(")");
                        x ^= 1;
                }
                printf("\n");
        }
}

int main(){
        int T; scanf("%d", &T);
        for(;T--;) solve();
	return 0;
}