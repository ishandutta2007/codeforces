#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int mark[3030][3030], area[3030][3030], L[3030][3030], R[3030][3030], U[3030][3030], D[3030][3030];
int X1[100050], Y1[100050];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ++x1; ++y1; ++x2; ++y2;
        X1[i] = x1; Y1[i] = y1;

        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                area[x][y] = 1;
                mark[x][y] = i + 1;
            }
        }
        for (int x = x1; x < x2; ++x) {
            U[x][y2 - 1] = 1;
            D[x][y1] = 1;
        }
        for (int y = y1; y < y2; ++y) {
            R[x2 - 1][y] = 1;
            L[x1][y] = 1;
        }
    }

    for (int x = 1; x <= 3000; ++x) {
        for (int y = 1; y <= 3000; ++y) {
            area[x][y] += area[x - 1][y] + area[x][y - 1] - area[x - 1][y - 1];
        }
    }
    for (int y = 1; y <= 3000; ++y) {
        for (int x = 1; x <= 3000; ++x) {
            U[x][y] += U[x - 1][y];
            D[x][y] += D[x - 1][y];
        }
    }
    for (int x = 1; x <= 3000; ++x) {
        for (int y = 1; y <= 3000; ++y) {
            R[x][y] += R[x][y - 1];
            L[x][y] += L[x][y - 1];
        }
    }

    int sol[100050], solc = 0, sola[100050] = {};

    for (int i = 0; i < n; ++i) {
        int x1 = X1[i], y1 = Y1[i];
        for (int s = 1; x1 + s - 1 <= 3000 && y1 + s - 1 <= 3000; ++s) {
            int x2 = x1 + s - 1, y2 = y1 + s - 1;
            
            int A = area[x2][y2] - area[x1 - 1][y2] - area[x2][y1 - 1] + area[x1 - 1][y1 - 1];
            if (A != s * s) {
                break;
            }

            int l = L[x1][y2] - L[x1][y1 - 1];
            if (l != s) {
                break;
            }

            int d = D[x2][y1] - D[x1 - 1][y1];
            if (d != s) {
                break;
            }

            int r = R[x2][y2] - R[x2][y1 - 1];
            if (r != s) {
                continue;
            }

            int u = U[x2][y2] - U[x1 - 1][y2];
            if (u != s) {
                continue;
            }

            for (int x = x1; x <= x2; ++x) {
                for (int y = y1; y <= y2; ++y) {
                    if (sola[mark[x][y]] == 0) {
                        sol[solc++] = mark[x][y];
                        sola[mark[x][y]] = 1;
                    }
                }
            }
            printf("YES %d\n", solc);
            for (int u = 0; u < solc; ++u) {
                printf("%d%c", sol[u], u + 1 == solc ? '\n' : ' ');
            }
            return 0;
        }
    }

    puts("NO");

    return 0;
}