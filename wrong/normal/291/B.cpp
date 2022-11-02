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
    getline(cin, s);

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == ' ') {
            continue;
        } else if (s[i] == '"') {
            int j = ++i;
            while (s[j] != '"') {
                ++j;
            }
            cout << '<' << s.substr(i, j - i) << '>' << endl;
            i = j;
        } else {
            int j = i;
            while (j < (int)s.size() && s[j] != ' ') {
                ++j;
            }
            cout << '<' << s.substr(i, j - i) << '>' << endl;
            i = j;
        }
    }

    return 0;
}