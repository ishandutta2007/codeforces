#include <algorithm>
#include <cassert>
// #include <chrono>
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
// #include <random>
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
typedef pair<double, double> pdd;
typedef pair<double, pdd> pddd;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int par[1000000];
int n, m;
int deg[1000000];

int find(int x) {
    return par[x] == x ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
    par[find(x)] = find(y);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
        deg[a]++;
        deg[b]++;
    }
    map<int, vector<int>> dp;
    for(int i = 1; i <= n; i++) {
        dp[find(i)].push_back(i);
    }
    int ret = 0;
    for(auto x: dp) {
        if(x.second.size() <= 2) continue;
        bool good = true;
        for(int out: x.second) {
            if(deg[out] != 2) good = false;
        }
        if(good) ret++;
    }
    printf("%d\n", ret);
}