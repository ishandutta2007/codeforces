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
char buf[10];
set<int> lhs;
set<int> rhs;
ll ret;
vector<int> unknown;

void update(int idx) {
    if(!rhs.empty() && idx >= *rhs.begin()) {
        rhs.insert(idx);
        return;
    }
    if(!lhs.empty() && idx <= *lhs.rbegin()) {
        lhs.insert(idx);
        return;
    }
    unknown.push_back(idx);
}

void query(int idx) {
    if(!rhs.empty() && idx > *rhs.begin()) {
        printf("0\n");
        exit(0);
    }
    if(!lhs.empty() && idx < *lhs.rbegin()) {
        printf("0\n");
        exit(0);
    }
    if(rhs.count(idx)) {
        rhs.erase(idx);
    }
    else if(lhs.count(idx)) {
        lhs.erase(idx);
    }
    else {
        ret *= 2;
        ret %= 1000000007;
    }
    for(int out: unknown) {
        if(out > idx) {
            rhs.insert(out);
        }
        else if(out < idx) {
            lhs.insert(out);
        }
    }
    unknown.clear();
}

int main() {
    scanf("%d\n", &n);
    ret = 1;
    while(n--) {
        int idx;
        scanf("%s%d\n", buf, &idx);
        if(strlen(buf) == 3) {
            update(idx);
        }
        else {
            query(idx);
        }
    }
    ll scale = 1;
    for(int out: unknown) {
        if(!rhs.empty() && out > *rhs.begin()) continue;
        if(!lhs.empty() && out < *lhs.rbegin()) continue;
        scale++;
    }
    printf("%lld\n", (ret*scale)%1000000007);
}