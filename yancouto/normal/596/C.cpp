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

int dd[300000];
int *dig = dd + 120000;
int w[200009];
int main() {
        int i, n, x, y;
        scanf("%d", &n);
        set<pii> s;
        for(i = 0; i < n; i++) {
                scanf("%d %d", &x, &y);
                dig[y - x]++;
                s.insert(pii(x, y));
        }
        for(i = 0; i < n; i++)
                scanf("%d", &w[i]);
        for(i = n - 1; i >= 0; i--) {
                if(dig[w[i]] == 0) { puts("NO"); return 0; }
                x = y = 0;
                if(w[i] >= 0) y = w[i];
                else x = -w[i];
                dig[w[i]]--;
                x += dig[w[i]];
                y += dig[w[i]];
                if(s.count(pii(x + 1, y)) || s.count(pii(x, y + 1))) { puts("NO"); return 0; }
                s.erase(pii(x, y));
        }
        puts("YES");
        for(i = 0; i < n; i++) {
                x = y = 0;
                if(w[i] >= 0) y = w[i];
                else x = -w[i];
                printf("%d %d\n", x + dig[w[i]], y + dig[w[i]]); 
                dig[w[i]]++;
        }
}