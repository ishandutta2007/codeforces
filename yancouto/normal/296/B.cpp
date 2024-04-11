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

void prn(int x) {
    printf("%d\n", x);
    exit(0);
}
char s[100009], w[100009];
ll pot[200010];
int n;
ll all_eq() {
    int i;
    ll v = 1;
    for(i = 0; i < n; i++) {
        if(s[i] != '?' || w[i] != '?') continue;
        v = mod(v * 10ll);
    }
    return v;
}

ll all_big() {
    int i;
    ll v = 1;
    for(i = 0; i < n; i++) {
        if(s[i] != '?' && w[i] != '?') continue;
        if(s[i] == '?' && w[i] == '?') v *= (10 * 9) / 2 + 10;
        else if(s[i] != '?') v *= s[i] - '0' + 1;
        else v *= 10 - (w[i] - '0');
        v = mod(v);
    }
    return v;
}
ll all_small() {
    int i;
    ll v = 1;
    for(i = 0; i < n; i++) {
        if(s[i] != '?' && w[i] != '?') continue;
        if(s[i] == '?' && w[i] == '?') v *= (10 * 9) / 2 + 10;
        else if(s[i] != '?') v *= 10 - (s[i] - '0');
        else v *= w[i] - '0' + 1;
        v = mod(v);
    }
    return v;
}

int main() {
    int i;
    pot[0] = 1;
    for(i = 1; i < 200009; i++)
        pot[i] = mod(pot[i - 1] * 10ll);
    scanf("%d", &n);
    scanf("%s %s", s, w);
    bool a_big = false, a_small = false;
    int numq = 0;
    for(i = 0; i < n; i++) {
        numq += (s[i] == '?') + (w[i] == '?');
        if(s[i] == '?' || w[i] == '?') continue;
        a_big |= s[i] > w[i];
        a_small |= s[i]< w[i];
    }
    ll all = pot[numq];
    if(a_big && a_small) prn(all - 0);
    ll good = 0;
    ll eq = all_eq();
    if(!a_big && !a_small) good += eq;
    if(!a_small) good += all_big() - eq * !a_big + modn;
    if(!a_big) good += all_small() - eq * !a_small + modn;
    prn(mod(all - mod(good) + modn));
}