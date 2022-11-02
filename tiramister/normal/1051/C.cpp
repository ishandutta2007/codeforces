#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), cnt(100, 0);
    for (auto& v : a) {
        cin >> v;
        ++cnt[--v];
    }

    int solo = 0;
    for (int i = 0; i < 100; ++i) {
        if (cnt[i] == 1) ++solo;
    }

    string ans(N, '?');
    int itr = 0;
    for (int i = 0; i < N; ++i) {
        if (cnt[a[i]] == 1) {
            ans[i] = 'A' + itr;
            itr = 1 - itr;
        } else if (cnt[a[i]] > 2 && solo % 2 != 0) {
            ans[i] = 'B';
            ++solo;
        } else {
            ans[i] = 'A';
        }
    }

    if (solo % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    return 0;
}