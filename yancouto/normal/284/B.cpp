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

char s[200009];
int ct[256];
int main() {
    int i;
    scanf("%*d");
    scanf("%s", s);
    for(i = 0; s[i]; i++)
        ct[s[i]]++;
    if(ct['I'] > 1) { puts("0"); return 0; }
    if(ct['I'] == 1) { puts("1"); return 0; }
    printf("%d\n", ct['A']);
}