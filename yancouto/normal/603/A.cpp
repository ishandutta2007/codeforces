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

int a[100009];
int main() {
        int i, j, n; char c;
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
                scanf(" %c", &c);
                a[i] = c - '0';
        }
        int p = a[0];
        int sz = 1, empty = 0;
        for(i = 1; i < n; i++) {
                if(a[i] != p) {
                        p = !p;
                        sz++;
                } else {
                        empty++;
                }
        }
        if(sz == n) { printf("%d\n", n); return 0; }
        printf("%d\n", sz + 1 + (empty > 1));
}