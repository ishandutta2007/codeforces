#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

vector<int> query(vector<int> a) {
    int L = a.size();
    string s(L, '*');
    for (int i = 0; i < L; ++i) s[i] = a[i] + 'a';
    cout << "? " << s << endl;

    string res;
    cin >> res;
    vector<int> ret(L);
    for (int i = 0; i < L; ++i) ret[i] = res[i] - 'a';

    return ret;
}

void answer(string ans) {
    cout << "! " << ans << endl;
}

int main() {
    string t;
    cin >> t;
    int N = t.length();

    vector<int> idx(N);
    for (int k = 0; k < 3; ++k) {
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            v[i] = i / mypow(26, k) % 26;
        }

        auto res = query(v);
        for (int i = 0; i < N; ++i) {
            idx[i] += mypow(26, k) * res[i];
        }
    }

    string ans(N, '*');
    for (int i = 0; i < N; ++i) {
        ans[idx[i]] = t[i];
    }

    answer(ans);
    return 0;
}