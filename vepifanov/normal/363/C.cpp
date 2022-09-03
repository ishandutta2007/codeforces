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
string s;
pair<char, int> q[200000];

int main () {
    cin >> s;
    int r = 0;
    int cur = 0;
    for (int i = 0; i < sz (s); ) {
        int j = i;
        while (j < sz (s) && s[j] == s[i]) j++;
        if (j - i >= 2)
            cur++;
        else {
            for (int k = 1; k < cur; k += 2) q[r - k - 1].se--;
            cur = 0;
        }
        q[r++] = mp (s[i], min (j - i, 2));
        i = j;
    }
    for (int k = 1; k < cur; k += 2) q[r - k - 1].se--;
    for (int i = 0; i < r; i++) printf ("%s", string (q[i].se, q[i].fi).c_str ());
    printf ("\n");
    return 0;
}