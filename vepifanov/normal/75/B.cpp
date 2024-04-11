#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
map<string, int> all;
string me;

int main() {
    cin >> me;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x, tmp, y;
        cin >> x >> tmp;
        if (tmp == "posted") {
            cin >> tmp >> y >> tmp;
            y.erase (sz (y) - 2, 2);
            if (x == me || y == me) { all[x] += 15; all[y] += 15; }
        } else
        if (tmp == "commented") {
            cin >> tmp >> y >> tmp;
            y.erase (sz (y) - 2, 2);
            if (x == me || y == me) { all[x] += 10; all[y] += 10; }
        } else {
            cin >> y >> tmp;
            y.erase (sz (y) - 2, 2);
            if (x == me || y == me) { all[x] += 5; all[y] += 5; }
        }
        if (!all.count (x)) all[x] = 0;
        if (!all.count (y)) all[y] = 0;
    }                           
    map<string, int>::iterator it;
    vector<pair<int, string> > res;
    for (it = all.begin (); it != all.end (); it++) 
        if (it->fi != me)
            res.pb (mp (-(it->se), it->fi));
    sort (all (res));
    for (int i = 0; i < sz (res); i++)
        cout << res[i].se << endl;
    return 0;
}