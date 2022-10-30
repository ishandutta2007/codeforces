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
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

char S[1<<20];

int main()
{
    scanf("%s", S);

    int N = strlen(S);

    deque<int> sol;
    sol.push_back(N);
    for (int i = N - 2; i >= 0; --i) {
        if (S[i] == 'l') {
            sol.push_back(i + 1);
        } else {
            sol.push_front(i + 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d\n", sol[i]);
    }

    return 0;
}