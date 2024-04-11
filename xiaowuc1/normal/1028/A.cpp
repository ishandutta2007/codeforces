#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<double, pii> pdpii;
typedef pair<double, double> pdd;
typedef pair<double, pdd> pddd;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int r, c;
char g[150][150];

int main() {
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++) {
        scanf("%s", g[i]);
    }
    int lx = 1000;
    int rx = 0;
    int ly = 1000;
    int ry = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(g[i][j] != 'B') continue;
            lx = min(lx, i);
            rx = max(rx, i);
            ly = min(ly, j);
            ry = max(ry, j);
        }
    }
    printf("%d %d\n", (lx+rx)/2 + 1, (ly+ry)/2 + 1);
}