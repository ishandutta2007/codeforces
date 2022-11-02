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

Int gcd(Int m, Int n)
{
    return n ? gcd(n, m % n) : m;
}

int main()
{
    Int p, q;
    cin >> p >> q;

    int n;
    Int A[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    if (n >= 2 && A[n - 1] == 1) {
        ++A[n - 2];
        --n;
    }

    Int g = gcd(p, q);
    p /= g;
    q /= g;

    int m = 0;
    Int B[100];
    while (true) {
        B[m++] = p / q;
        if (q == 1) {
            break;
        }

        Int nq = p % q;
        Int np = q;
        Int ng = gcd(nq, np);
        p = np / ng;
        q = nq / ng;
    }

    if (n != m) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if (A[i] != B[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }

    return 0;
}