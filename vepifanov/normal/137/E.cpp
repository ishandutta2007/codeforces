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

int tree[2000000];
string s;

int add (int x, int l, int r, int p, int q) {
    if (r < p || l > p) re tree[x];
    if (l == r) re tree[x] = max (tree[x], q);
    int s = (l + r) / 2;
    re tree[x] = max (add (x * 2, l, s, p, q), add (x * 2 + 1, s + 1, r, p, q));
}

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re max (get (x * 2, l, s, lc, rc), get (x * 2 + 1, s + 1, r, lc, rc));
}
 
int main () { 
    cin >> s;
    n = sz (s);
    int sum = 2 * n;
    int N = 3 * n + 1;
    while (N & (N - 1)) N++;
    add (1, 0, N - 1, sum, n);
    int ans = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') sum++; else sum -= 2;
        int pos = get (1, 0, N - 1, sum, N - 1);
        if (pos > i) {
            if (pos - i > ans) { ans = pos - i; cnt = 0; }
            if (pos - i == ans) cnt++;
        }
        add (1, 0, N - 1, sum, i);
    }
    if (ans == 0) printf ("No solution\n"); else printf ("%d %d\n", ans, cnt);
    return 0; 
}