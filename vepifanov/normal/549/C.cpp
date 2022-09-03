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
#define prev PREV
                         
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

int main () {
    scanf ("%d%d", &n, &m);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x & 1)
            odd++;
        else
            even++;
    }
    if (n == m) {
        if (odd & 1)
            printf ("Stannis\n");
        else    
            printf ("Daenerys\n");
        re 0;
    }
    int s = (n - m + 1) / 2;
    int d = (n - m) / 2;
    if (s >= even && (m & 1)) {
        printf ("Stannis\n");
        re 0;
    }
    if (d >= odd || (d >= even && (m & 1) == 0)) {
        printf ("Daenerys\n");
        re 0;
    }
    if (s > d) {
        printf ("Stannis");
    } else {
        printf ("Daenerys");        
    }
    return 0;
}