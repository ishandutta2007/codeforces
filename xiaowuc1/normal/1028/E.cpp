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

int b[200000];
ll a[200000];

int changed[200000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        a[(i+1)%n] = b[i]+1;
    }
    while(true) {
        bool bad = false;
        for(int i = n-1; i >= 0; i--) {
            if(b[i] != a[i] % a[(i+1)%n]) {
                if(++changed[i] > 10) {
                    printf("NO\n");
                    return 0;
                }
                ll go = a[i] / (a[(i+1)%n]);
                go *= a[(i+1)%n];
                go += b[i];
                if(go <= a[i]) {
                    go += a[(i+1)%n];
                }
                if(go > 1000000000000000000) {
                    printf("NO\n");
                    return 0;
                }
                a[i] = go;
                bad = true;
            }
        }
        if(!bad) break;
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) {
        printf("%lld", a[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
}