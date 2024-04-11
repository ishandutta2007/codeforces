#include <iostream>
#include <time.h>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

using ll = long long;

template <typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

mt19937 mert(ll(time(0)));
int q = 0;

int query(int t, int x) {
    cout << "?>"[t] << " " << x << endl;
    ++q;
    int res;
    cin >> res;
    return res;
}

int findmax() {
    // ok >= max
    int ok = 1e9 + 1, ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        int res = query(1, mid);
        if (res) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    return ok;
}

void answer(int x1, int d) {
    cout << "! " << x1 << " " << d << endl;
}

int main() {
    int N;
    cin >> N;

    int M = findmax();
    vector<int> a;
    bool asked[N];
    fill(asked, asked + N, false);
    while (q < 60 && !all_of(asked, asked + N, [](bool b) { return b; })) {
        while (true) {
            int i = mert() % N;
            if (asked[i]) continue;

            a.push_back(query(0, i + 1));
            asked[i] = true;
            break;
        }
    }

    sort(a.begin(), a.end());
    int g = M - a.front();
    for (int i = 0; i < a.size() - 1; ++i) {
        g = gcd(g, a[i + 1] - a[i]);
    }

    answer(M - (N - 1) * g, g);
    return 0;
}