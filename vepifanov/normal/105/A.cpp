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
double k;
vector<pair<string, int> > res;
set<string> all;

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if ((int)(k * x + 0.000001) >= 100) {
            res.pb (mp (s, (int)(k * x + 0.000001)));
            all.insert (s);
        }   
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (all.count (s) == 0) res.pb (mp (s, 0));
    }
    sort (all (res));
    cout << sz (res) << endl;
    for (int i = 0; i < sz (res); i++)
        cout << res[i].fi << " " << res[i].se << endl;

    return 0;
}