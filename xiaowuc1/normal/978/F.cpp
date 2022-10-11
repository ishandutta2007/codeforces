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

int skill[1000000];
pii l[1000000];
int ret[1000000];
set<int> bad[1000000];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &skill[i]);
        l[i] = pii(skill[i], i);
    }
    sort(l, l+n);
    while(k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        bad[a].insert(b);
        bad[b].insert(a);
    }
    int lhs = 0;
    for(int i = 0; i < n; i++) {
        while(l[lhs].first < l[i].first) lhs++;
        ret[l[i].second] = lhs;
        for(int out: bad[l[i].second]) {
            if(skill[out] < skill[l[i].second]) {
                ret[l[i].second]--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d", ret[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
}