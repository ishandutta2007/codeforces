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

int n;

int main() {
    scanf("%d", &n);
    vector<pii> v;
    ll scale = 1;
    for(int i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        int three = 0;
        int two = 0;
        while(t%3 == 0) {
            t /= 3;
            three++;
        }
        while(t%2 == 0) {
            t /= 2;
            two++;
        }
        scale = t;
        v.push_back(pii(-three, two));
    }
    sort(v.begin(), v.end());
    vector<ll> ret;
    for(pii out: v) {
        ll c = 1;
        for(int i = 0; i < -out.first; i++) {
            c *= 3;
        }
        for(int i = 0; i < out.second; i++) {
            c *= 2;
        }
        ret.push_back(c);
    }
    for(int i = 0; i < ret.size(); i++) {
        printf("%lld", ret[i] * scale);
        if(i == ret.size()-1) printf("\n");
        else printf(" ");
    }
    return 0;
}