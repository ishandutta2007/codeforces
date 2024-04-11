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

map<string, int> all;

int main () {
    cin >> n;
    all["void"] = 0;
    all["errtype"] = -1;
    for (int i = 0; i < n; i++) {
        string t, a, b;
        cin >> t >> a;
        if (t == "typedef") {
            cin >> b;
            int x = 0, y = 0, res = -1;
            while (a[0] == '&') {
                a.erase (0, 1);
                x++;
            }
            while (a[sz (a) - 1] == '*') {
                a.erase (sz (a) - 1, 1);
                y++;
            }
            if (all.count (a)) {
                res = all[a];
                if (res != -1) res = res + y - x;
                if (res < 0) res = -1;
            }   
            all[b] = res;
        } else {
            int x = 0, y = 0, res = -1;
            while (a[0] == '&') {
                a.erase (0, 1);
                x++;
            }
            while (a[sz (a) - 1] == '*') {
                a.erase (sz (a) - 1, 1);
                y++;
            }
            if (all.count (a)) {
                res = all[a];
                if (res != -1) res = res + y - x;
                if (res < 0) res = -1;
            }
            if (res != -1) {
                if (res == -1) cout << "errtype" << endl; else {
                    cout << "void";
                    for (int j = 0; j < res; j++) cout << "*";
                    cout << endl;
                }
            } else cout << "errtype" << endl;
        }
    }
    return 0;
}