#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int main()
{
    int n;
    deque<int> A;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        A.push_back(a);
    }

    int bits = 0, maxb = 0;
    while (!A.empty()) {
        int f = A.front();
        int cnt = 0;
        while (!A.empty() && A.front() == f) {
            A.pop_front();
            ++cnt;
        }
        if (cnt % 2 == 1) {
            ++bits;
        }
        chmax(maxb, f + 1);

        while (cnt >= 2) {
            A.push_front(f + 1);
            cnt -= 2;
        }
    }

    cout << maxb - bits << endl;

    return 0;
}