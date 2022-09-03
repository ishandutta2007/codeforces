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

const int N = 5000000;

int n;
int m;
ll c, hr, hb, wr, wb;

int main () {
    cin >> c >> hr >> hb >> wr >> wb;
    ll ans = 0;
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i * wr <= c && i <= N; i++)
            ans = max (ans, i * hr + ((c - i * wr) / wb) * hb);
        ll tmp = c / wr;
        for (int i = 0; i <= tmp && i <= N; i++)
            ans = max (ans, (tmp - i) * hr + ((c - (tmp - i) * wr) / wb) * hb);
        swap (hr, hb);                  
        swap (wr, wb);
    }
    cout << ans << endl;
    return 0;
}