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
int res[4];
int s1[4], s2[4];
map<string, int> all;
string name[4];
int w[4][4];

int get (string s) {
    if (all.find (s) != all.end ()) re all[s];
    all[s] = m;
    name[m] = s;
    m++;
    re m - 1;
}
        
int main () {
    for (int i = 0; i < 5; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        int x = get (a);
        int y = get (b);
        int p = c[0] - '0', q = c[2] - '0';
        w[x][y] = w[y][x] = 1;
        res[x] += 3 * int (p > q) + int (p == q);
        res[y] += 3 * int (p < q) + int (p == q);
        s1[x] += p;
        s1[y] += q;
        s2[x] += q;
        s2[y] += p;
    }
    int x = get ("BERLAND"), y = 0;
    for (int i = 0; i < 4; i++)
        if (i != x && !w[x][i])
            y = i;
    int ap = -1, aq = -1;
    for (int p = 1; p <= 100; p++)
        for (int q = 0; q < p; q++) {
            res[x] += 3 * int (p > q) + int (p == q);
            res[y] += 3 * int (p < q) + int (p == q);
            s1[x] += p;
            s1[y] += q;
            s2[x] += q;
            s2[y] += p;

            int ok = 0;
            for (int t = 0; t < 4; t++) {
                if (res[t] < res[x]) continue;
                if (res[t] == res[x]) {
                    if (s1[t] - s2[t] < s1[x] - s2[x]) continue;
                    if (s1[t] - s2[t] == s1[x] - s2[x]) {
                        if (s1[t] < s1[x]) continue;
                        if (s1[t] == s1[x]) {
                            if (name[t] > name[x]) continue;
                        }   
                    }   
                }   
                ok++;
            }
            if (ok <= 2) {
                if (ap == -1 || ap - aq > p - q || ap - aq == p - q && aq > q) {
                    ap = p;
                    aq = q;
                }
            }

            res[x] -= 3 * int (p > q) + int (p == q);
            res[y] -= 3 * int (p < q) + int (p == q);
            s1[x] -= p;
            s1[y] -= q;
            s2[x] -= q;
            s2[y] -= p;
        }
    if (ap == -1) printf ("IMPOSSIBLE\n"); else printf ("%d:%d\n", ap, aq);
    return 0;
}