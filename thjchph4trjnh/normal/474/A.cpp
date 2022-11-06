#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

char prev[256];
char next[256];

void solve() {
    next['a'] = 's';
    next['b'] = 'n';
    next['c'] = 'v';
    next['d'] = 'f';
    next['e'] = 'r';
    next['f'] = 'g';
    next['g'] = 'h';
    next['h'] = 'j';
    next['i'] = 'o';
    next['j'] = 'k';
    next['k'] = 'l';
    next['l'] = ';';
    next['m'] = ',';
    next['n'] = 'm';
    next['o'] = 'p';
    next['p'] = '[';
    next['q'] = 'w';
    next['r'] = 't';
    next['s'] = 'd';
    next['t'] = 'y';
    next['u'] = 'i';
    next['v'] = 'b';
    next['w'] = 'e';
    next['x'] = 'c';
    next['y'] = 'u';
    next['z'] = 'x';
    next[';'] = '\'';
    next['.'] = '/';
    next[','] = '.';
    next['\t'] = 'q';
    next['\''] = '\n';
    FOR(i, 0, 256) prev[next[i]] = i;
    char t, s[110];
    scanf("%c %s", &t, s);
    if (t == 'R') FOR(i, 0, strlen(s)) printf("%c", prev[s[i]]);
    else FOR(i, 0, strlen(s)) printf("%c", next[s[i]]);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}