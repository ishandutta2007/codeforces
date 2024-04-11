#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 1e5;
const int INF = 1e9 + 19;
 
int n;
double ans, p[N], a[N];

int main(){
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    double pr = 1;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        p[i] = u * 1.0 / 100;
        a[i] = 1 - p[i];
        pr *= 1 - a[i];
    }
    ans = n;
    for (int it = 0; it < 2e6 + 100; it++) {
        double mx = -1;
        int id = -1;
        for (int i = 0; i < n; i++) {
            double od = 1 - a[i];
            double nw = 1 - a[i] * (1 - p[i]);
            if (nw / od > mx) {
                mx = nw / od;
                id = i;
            }
        }        
        a[id] *= 1 - p[id];
        if (a[id] < 1e-300) a[id] = 0;
        ans += 1 - pr;
        pr *= mx;
    }
    printf("%.10lf\n", ans);
    return 0;
}