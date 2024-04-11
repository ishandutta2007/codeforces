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
typedef unsigned long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const Int MAX = 10000050;
int occ[MAX] = {}, isp[MAX];

int main()
{
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        ++occ[a];
    }

    for (int i = 1; i < MAX; ++i) {
        occ[i] += occ[i - 1];
    }

    for (int i = 2; i < MAX; ++i) {
        isp[i] = 1;
    }
    Int n = 1;
    for (int i = 2; i < MAX; ++i) {
        if (isp[i]) {
            for (int j = i+i; j < MAX; j += i) {
                isp[j] = 0;
            }

            Int cnt = 0;
            for (Int p = i; p < MAX; p *= i) {
                for (Int q = p; q - 1 < MAX; q += p) {
                    cnt += k - occ[q - 1];
                }
            }

            Int lo = 0, hi = 10000000000000LL;
            while (hi - lo > 1) {
                Int mid = (hi + lo) / 2;
                Int cc = 0;
                for (Int p = i; p <= mid; p *= i) {
                    cc += mid / p;
                }
                if (cc >= cnt) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            //if(cnt!=0)
            //cerr << i << ' ' << lo << ' ' << hi << endl;

            chmax(n, hi);
        }
    }

    cout << n << endl;

    return 0;
}