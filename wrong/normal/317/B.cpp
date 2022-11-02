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

const int INF = 9090901;
const Int INFLL = 9090909090901LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

void trans(int F[180][180])
{
    while (true) {
        bool henka = false;
        int G[180][180] = {{}};
        for (int i = 0; i < 180; ++i) {
            for (int j = 0; j < 180; ++j) {
                if (F[i][j] >= 4) {
                    int a=F[i][j]/4;
                    G[i-1][j]+=a; G[i][j-1]+=a;
                    G[i+1][j]+=a; G[i][j+1]+=a;
                    F[i][j] %= 4;
                    henka=true;
                }
                G[i][j] += F[i][j];
            }
        }
        for (int i = 0; i < 180; ++i) {
            for (int j = 0; j < 180; ++j) {
                F[i][j] = G[i][j];
            }
        }
        if(!henka) break;
    }
}

void get(int F[180][180], int n)
{
    if (n < 4) {
        F[90][90] = n;
        return;
    }
    int T[180][180] = {{}};
    get(T, n / 2);
    for (int i = 0; i < 180; ++i) {
        for (int j = 0; j < 180; ++j) {
            F[i][j] = T[i][j] * 2;
        }
    }
    F[90][90] += n % 2;
    //trans(F);
}

int main()
{
    int n, t;
    cin >> n >> t;

    int F[180][180] = {{}};
    get(F, n);trans(F);

    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        x += 90;
        y += 90;
        if (x < 0 || y < 0 || x >= 180 || y >= 180) {
            cout << 0 << endl;
        } else {
            cout << F[x][y] << endl;
        }
    }

    return 0;
}