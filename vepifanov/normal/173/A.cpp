#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int sa[1000001], sb[1000001];
string s, t;

int main () {
    scanf ("%d", &n);
    cin >> s >> t;
    for (int i = 0; i < sz (s); i++) s[i] -= 'A' - 'a';
    for (int i = 0; i < sz (t); i++) t[i] -= 'A' - 'a';
    int p = sz (s), q = sz (t);
    int ca = 0, cb = 0;
    sa[0] = sb[0] = 0;
    for (int i = 0; i < p * q; i++) {
        int a = i % p, b = i % q;
        if (s[a] == 's' && t[b] == 'p' || s[a] == 'p' && t[b] == 'r' || s[a] == 'r' && t[b] == 's') cb++;
        if (s[a] == 'p' && t[b] == 's' || s[a] == 'r' && t[b] == 'p' || s[a] == 's' && t[b] == 'r') ca++;
        sa[i + 1] = ca;
        sb[i + 1] = cb;
    }
    int r = p * q;
    printf ("%d %d\n", (n / r) * sa[r] + sa[n % r], (n / r) * sb[r] + sb[n % r]);
    return 0;
}