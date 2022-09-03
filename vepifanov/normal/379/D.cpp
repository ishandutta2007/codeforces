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
int a[50];
int b[50];
int c[50];
int k, x;

int out (int n, int a, int b, int c) {
    if (n == 1) printf ("%c\n", a + 'A'); else
    if (n == 2) printf ("%c%c\n", a + 'A', b + 'A'); else {
        string res (n, 'B');
        res[0] = a + 'A';
        res[n - 1] = b + 'A';
        if (a == 0) {
            for (int i = 0; i < c; i++) {
                res[2 * i] = 'A';
                res[2 * i + 1] = 'C';
            }
        } else
        if (b == 2) {
            for (int i = 0; i < c; i++) {
                res[n - 2 * i - 1] = 'C';
                res[n - 2 * i - 2] = 'A';
            }
        } else {
            for (int i = 0; i < c; i++) {
                res[2 * i + 1] = 'A';
                res[2 * i + 2] = 'C';
            }
        }
        printf ("%s\n", res.c_str ());
    }
    re 0;
}

int main () {
    scanf ("%d%d%d%d", &k, &x, &n, &m);
    for (int a1 = 0; a1 < 3; a1++)
        for (int b1 = 0; b1 < 3; b1++)
            if (n > 1 || a1 == b1) {
                int ac1 = 0, ac2 = 0;
                if (n >= 2) {
                    if (n == 2) {
                        if (a1 == 0 && b1 == 2) ac1 = ac2 = 1;
                    } else {
                        if (a1 == 0) {
                            if (n & 1) ac2 = n / 2; else {
                                if (b1 == 2) ac2 = n / 2; else ac2 = n / 2 - 1;
                            }
                        } else
                        if (b1 == 2) ac2 = (n - 1) / 2; else ac2 = n / 2 - 1;
                    }
                }   
                for (int ac = ac1; ac <= ac2; ac++) {
                    for (int a2 = 0; a2 < 3; a2++)
                        for (int b2 = 0; b2 < 3; b2++)
                            if (m > 1 || a2 == b2) {
                                int bc1 = 0, bc2 = 0;
                                if (m >= 2) {
                                    if (m == 2) {
                                        if (a2 == 0 && b2 == 2) bc1 = bc2 = 1;
                                    } else {
                                        if (a2 == 0) {
                                            if (m & 1) bc2 = m / 2; else {
                                                if (b2 == 2) bc2 = m / 2; else bc2 = m / 2 - 1;
                                            }
                                        } else
                                        if (b2 == 2) bc2 = (m - 1) / 2; else bc2 = m / 2 - 1;
                                    }
                                }
                                for (int bc = bc1; bc <= bc2; bc++) {
                                    a[0] = a1;
                                    b[0] = b1;
                                    c[0] = ac;
                                    a[1] = a2;
                                    b[1] = b2;
                                    c[1] = bc;
                                    for (int i = 2; i < k; i++) {
                                        c[i] = c[i - 1] + c[i - 2] + int (b[i - 2] == 0 && a[i - 1] == 2);
                                        a[i] = a[i - 2];
                                        b[i] = b[i - 1];
                                        if (c[i] > x) break;
                                    }
                                    if (c[k - 1] == x) {
                                        out (n, a1, b1, ac);
                                        out (m, a2, b2, bc);
                                        re 0;
                                    }
                                }
                    
                            }
                }
            }   
    printf ("Happy new year!\n");
    return 0;
}