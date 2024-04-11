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

map<int, set<int>> dp;

int main() {
    int n;
    scanf("%d", &n);
    int highest = -1;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        dp[x].insert(i);
        highest = max(highest, x);
    }
    vector<int> ret;
    while(!dp.empty()) {
        vector<int> curr;
        auto cand = dp.begin();
        int currV = cand->first;
        curr.push_back(*dp[currV].begin());
        int currI = curr[0];
        dp[currV].erase(currI);
        if(dp[currV].empty()) dp.erase(currV);
        while(true) {
            currV++;
            if(!dp.count(currV)) break;
            set<int>::iterator it = dp[currV].lower_bound(currI);
            if(it == dp[currV].end()) break;
            currI = *it;
            dp[currV].erase(currI);
            if(dp[currV].empty()) dp.erase(currV);
            curr.push_back(currI);
        }
        if(curr.size() > ret.size()) {
            ret = curr;
        }
    }
    printf("%d\n", ret.size());
    for(int i = 0; i < ret.size(); i++) {
        printf("%d", ret[i]);
        if(i + 1 == ret.size()) printf("\n");
        else printf(" ");
    }
}