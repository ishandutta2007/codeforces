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

int n;
int lx[200000];
int ly[200000];
int rx[200000];
int ry[200000];

bool valid(int x, int y) {
    int r = 0;
    for(int i = 0; i < n; i++) {
        if(x >= lx[i] && x <= rx[i] && y >= ly[i] && y <= ry[i]) r++;
    }
    return r >= n-1;
}

void solve(int x, int y) {
    if(valid(x, y)) {
        printf("%d %d\n", x, y);
        exit(0);
    }
}

void analyze(int x) {
    vector<pii> ys;
    for(int i = 0; i < n; i++) {
        if(x >= lx[i] && x <= rx[i]) {
            ys.push_back(pii(2 * ly[i], 1));
            ys.push_back(pii(2 * ry[i] + 1, -1));
        }
    }
    sort(ys.begin(), ys.end());
    int amt = 0;
    for(pii out: ys) {
        amt += out.second;
        if(out.first % 2) {
            out.first--;
        }
        if(amt >= n-1) {
            solve(x, (out.first)/2);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
    }
    vector<pii> xs;
    for(int i = 0; i < n; i++) {
        xs.push_back(pii(lx[i] * 2, 1));
        xs.push_back(pii(rx[i] * 2 + 1, -1));
    }
    sort(xs.begin(), xs.end());
    int amt = 0;
    for(pii out: xs) {
        amt += out.second;
        if(out.first % 2) {
            out.first--;
        }
        if(amt >= n-1) {
            analyze((out.first)/2);
        }
    }
    assert(false);
}