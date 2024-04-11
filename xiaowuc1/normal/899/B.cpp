#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

int main() {
    vector<int> v;
    for(int i = 0; i < 96; i++) {
        if(i%12 == 1) {
            if(i%48 == 1) {
                v.push_back(29);
            }
            else {
                v.push_back(28);
            }
            continue;
        }
        if(i%12 == 3 || i%12 == 5 || i%12 == 8 || i%12 == 10) {
            v.push_back(30);
            continue;
        }
        v.push_back(31);
    }
    int n;
    scanf("%d", &n);
    vector<int> u;
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        u.push_back(t);
    }
    for(int a = 0; a + n <= v.size(); a++) {
        int m = 0;
        for(int i = 0; i < u.size(); i++) {
            if(u[i] == v[a+i]) m++;
        }
        if(m == n) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}