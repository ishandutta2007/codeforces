#include <iostream>
#include <map>

using lint = long long;

using namespace std;

int main() {
    int N;
    lint P, K;
    cin >> N >> P >> K;

    map<lint, lint> cnt;
    for (int i = 0; i < N; ++i) {
        lint A;
        cin >> A;
        lint quad = 1;
        for (int j = 0; j < 4; ++j) {
            (quad *= A) %= P;
        }
        lint B = (quad + P - (A * K % P)) % P;
        if (!cnt.count(B)) cnt[B] = 0;
        ++cnt[B];
    }

    lint ans = 0;
    for (auto p : cnt) {
        ans += p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}