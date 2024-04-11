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

const int TT = 2000;

int n;
int m;
string s[100];
int x[100];
int y[100];
int p[100];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int it = 0; it < TT; it++) {
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            p[i] = i;
        }
        int i;
        for (i = 0; i < n; i++) {
            int j = 0;
            while (j < n && x[j] != y[j]) j++;
            if (j == n) break;
            vi v;
            for (int k = i; k < n; k++)
                if (s[p[k]][j] == '1')
                    v.pb (k);
            if (v.empty ()) break;
            int k = v[rand () % sz (v)];
            swap (p[k], p[i]);
            for (int t = 0; t < n; t++)
                if (s[p[i]][t] == '1')
                    y[t]++;
        }
        int ok = 1;
        for (int j = 0; j < n; j++)
            if (x[j] == y[j])
                ok = 0;
        if (ok) {
            printf ("%d\n", i);
            sort (p, p + i);
            for (int j = 0; j < i; j++)
                printf ("%d ", p[j] + 1);
            printf ("\n");
            re 0;
        }
    }
    printf ("-1\n");
    return 0;
}