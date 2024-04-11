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

int n;
char s[5009];
int eq[5003][5003];

bool gr(int i, int j, int sz) {
        if(eq[i][j] >= sz) return false;
        return s[j + eq[i][j]] > s[i + eq[i][j]];
}

int memo[5003][5003][2];
ll solve(int i, int sz, bool check) {
        if(i == n) return 1;
        if(i + sz > n || s[i] == '0') return 0;
        int &r = memo[i][sz][check];
        if(r != -1) return r;
        ll ans = solve(i, sz + 1, false);
        if(!check || gr(i - sz, i, sz)) ans += solve(i + sz, sz, true);
        return r = mod(ans);
}

int main() {
        int i, j, k;
        memset(memo, -1, sizeof memo);
        memset(eq, -1, sizeof eq);
        scanf("%d", &n);
        scanf("%s", s);
        for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                        if(eq[i][j] == -1) {
                                for(k = 0; i + k < n && j + k < n && s[i + k] == s[j + k]; k++);
                                for(int g = k; g >= 0; g--) eq[i + g][j + g] = k - g;
                        }
        printf("%d\n", int(solve(0, 1, false)));
}