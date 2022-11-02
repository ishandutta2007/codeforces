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

int gcd(int n, int m)
{
    return m ? gcd(m, n % m) : n;
}

int main()
{
    int n, A[128];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int G = A[0];
    for (int i = 1; i < n; ++i) {
        G = gcd(G, A[i]);
    }

    int num = *max_element(A, A + n) / G;
    int rem = num - n;

    if (rem % 2 == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }

    return 0;
}