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
    int G[5050];
    G[0] = 0;
    G[1] = 1;

    for (int i = 2; i <= 5000; ++i) {
        int A[5050] = {};
        for (int j = 0; j < i; ++j) {
            if (j == 0 || j == i - 1) {
                A[G[i - 2]] = 1;
            } else {
                A[G[j - 1] ^ G[i - j - 2]] = 1;
            }
        }

        for (int j = 0; j <= 5000; ++j) {
            if (A[j] == 0) {
                G[i] = j;
                break;
            }
        }
    }

    string S;
    cin >> S;

    int ok[5050] = {};

    for (int i = 0; i < (int)S.size(); ++i) {
        if (i == 0 || i == (int)S.size() - 1) {
            ok[i] = 0;
        } else {
            ok[i] = S[i - 1] == S[i + 1];
        }
    }

    vector<int> cs;
    vector<int> pos;
    for (int i = 0; i < (int)S.size(); ) {
        if (ok[i] == 0) {
            ++i;
            continue;
        }
        int j = i;
        while (j < (int)S.size() && ok[j]) {
            ++j;
        }
        cs.push_back(j - i);
        pos.push_back(i);
        i = j;
    }

    int grundy = 0;
    for (int i = 0; i < (int)cs.size(); ++i) {
        grundy ^= G[cs[i]];
    }

    if (grundy == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
        for (int j = 0; j < (int)cs.size(); ++j) {
            int sz = cs[j], gg = grundy ^ G[cs[j]];
            if (sz == 1 && gg == 0) {
                cout << pos[j] + 1 << endl;
                return 0;
            }
            if (sz > 1) {
                for (int k = 0; k < sz; ++k) {
                    if (k == 0 || k == sz - 1) {
                        if ((gg ^ G[sz - 2]) == 0) {
                            cout << pos[j] + 1 + k << endl;
                            return 0;
                        }
                    } else {
                        if ((gg ^ G[k - 1] ^ G[sz - k - 2]) == 0) {
                            cout << pos[j] + 1 + k << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}