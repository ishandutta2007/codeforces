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
    string s;
    cin >> s;

    int n;
    cin >> n;

    int freq[26] = {}, types = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (freq[s[i] - 'a'] == 0) {
            ++types;
        }
        freq[s[i] - 'a']++;
    }

    if (types > n) {
        cout << -1 << endl;
        return 0;
    }

    int lo = 0, hi = 1024;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        int req = 0;

        for (int i = 0; i < 26; ++i) {
            int need = freq[i] / mid;
            if (need * mid < freq[i]) ++need;
            req += need;
        }

        (req <= n ? hi : lo) = mid;
    }

    int printed = 0;
    cout << hi << endl;
    for (int i = 0; i < 26; ++i) {
        int need = freq[i] / hi;
        if (need * hi < freq[i]) ++need;
        printed += need;
        for (int j = 0; j < need; ++j) {
            cout << (char)('a' + i);
        }
    }

    for (int i = printed; i < n; ++i) {
        cout << 'z';
    }
    cout << endl;

    return 0;
}