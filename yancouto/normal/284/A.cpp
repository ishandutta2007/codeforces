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

int main() {
    int i, j, p;
    scanf("%d", &p);
    int tot = 0;
    for(i = 1; i < p; i++) {
        int g = 1;
        for(j = 1; j < p - 1; j++) {
            g = (g * i) % p;
            if(g == 1) break;
        }
        if(j == p - 1 && ((g * i) % p) == 1) tot++;
    }
    printf("%d\n", tot);
}