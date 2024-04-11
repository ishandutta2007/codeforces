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

const string name[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

int n;
int m;
pair<ii, ii> q[1000000];
int y[4], can[4];
set<ll> all[10001];
string s;

ll hash () {
    ll tmp = y[0];
    tmp = tmp * 10001 + y[1];
    tmp = tmp * 10001 + y[2];
    tmp = tmp * 10001 + y[3];
    re tmp;
}

int get (char c) {
    for (int i = 0; i < 4; i++)
        if (name[i][0] == c)
            re i;
    re 0;
}

int main() {
    cin >> n;
    cin >> s;
    int l = 0, r = 1;
    q[0] = mp (mp (0, 0), mp (0, 0));
    while (l < r) {
        pair<ii, ii> x = q[l++];
        y[0] = x.fi.fi; y[1] = x.fi.se; y[2] = x.se.fi; y[3] = x.se.se;
        int mx = y[0], t = 0;
        for (int i = 0; i < 4; i++) {
            mx = min (mx, y[i]);
            t += y[i];
        }   
        if (t == n) {
            for (int i = 0; i < 4; i++)
                if (y[i] == mx)
                    can[i] = 1;
            continue;
        }
        if (s[t] == '?') {
            for (int i = 0; i < 4; i++)
                if (y[i] == mx) {
                    y[i]++;
                    ll tmp = hash ();
                    if (!all[t].count (tmp)) {
                        all[t].insert (tmp);
                        q[r++] = mp (mp (y[0], y[1]), mp (y[2], y[3]));
                    }
                    y[i]--;
                }
        } else {
            int k = get (s[t]);
            y[k]++;
            ll tmp = hash ();
            if (!all[t].count (tmp)) {
                all[t].insert (tmp);
                q[r++] = mp (mp (y[0], y[1]), mp (y[2], y[3]));
            }
            y[k]--;
        }
    }
    for (int i = 0; i < 4; i++)
        if (can[i])
            cout << name[i] << endl;
    return 0;
}