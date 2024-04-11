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

int c1[10], c2[10];

int main () {
    cin >> s;
    n = sz (s);
    sort (all (s));
    reverse (all (s));
    for (int i = 0; i < sz (s); i++) c1[s[i] - '0']++;
    for (int i = 0; i < 10; i++) c2[i] = c1[i];
    int ans = c1[0], A = 0, B = 0;
    for (int a = 0; a <= c1[0] && a <= c2[0]; a++) 
        for (int b = 1; b < 10; b++) 
            if (c1[b] > 0 && c2[10 - b] > 0) {
                c1[0] -= a;
                c2[0] -= a;
                c1[b]--;
                c2[10 - b]--;
                int cur = a + 1;
                for (int j = 0; j <= 9; j++) cur += min (c1[j], c2[9 - j]);
                if (cur >= ans) {
                    ans = cur;
                    A = a;
                    B = b;
                }
                c1[b]++;
                c2[10 - b]++;
                c1[0] += a;
                c2[0] += a;
            }
    if (ans == c1[0]) printf ("%s\n%s\n", s.c_str (), s.c_str ()); else {
        string sa = "", sb = "";
        for (int i = 0; i < A; i++) {
            sa += '0';
            sb += '0';
            c1[0]--;
            c2[0]--;
        }
        c1[B]--;
        c2[10 - B]--;
        sa += char ('0' + B);
        sb += char ('0' + 10 - B);
        for (int i = 0; i <= 9; i++) {
            int tmp = min (c1[i], c2[9 - i]);
            c1[i] -= tmp;
            c2[9 - i] -= tmp;
            for (int j = 0; j < tmp; j++) {
                sa += char ('0' + i);
                sb += char ('0' + 9 - i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < c1[i]; j++) sa += char ('0' + i);
            for (int j = 0; j < c2[i]; j++) sb += char ('0' + i);
        }
        reverse (all (sa));
        reverse (all (sb));
        printf ("%s\n%s\n", sa.c_str (), sb.c_str ());
//      cout << ans << endl;
    }
    return 0;
}