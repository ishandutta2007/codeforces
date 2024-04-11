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

ll l[1000000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &l[i]);
    }
    if(n <= 2) {
        printf("0\n");
        return 0;
    }
    ll ret = n+1;
    for(int a = -1; a <= 1; a++) {
        for(int b = -1; b <= 1; b++) {
            int now = 0;
            if(a) now++;
            if(b) now++;
            ll orig = (l[0] + a);
            ll diff = (l[1] + b) - (l[0] + a);
            bool good = true;
            for(int i = 2; i < n; i++) {
                ll actual = orig + i * diff;
                if(abs(actual - l[i]) > 1) {
                    good = false;
                    break;
                }
                if(actual != l[i]) now++;
            }
            if(!good) continue;
            ret = min(ret, (ll)now);
        }
    }
    if(ret > n) ret = -1;
    printf("%lld\n", ret);
}