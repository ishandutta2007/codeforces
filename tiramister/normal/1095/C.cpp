#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> ans;
    while (N > 0) {
        for (int k = 30; k >= 0; --k) {
            if (N < (1 << k)) continue;
            N -= (1 << k);
            ans.push_back(1 << k);
        }
    }

    if (ans.size() > K) {
        cout << "NO" << endl;
        return 0;
    }

    int itr = 0;
    while (ans.size() < K) {
        while (itr < ans.size() && ans[itr] == 1) {
            ++itr;
        }

        if (itr == ans.size()) break;

        ans[itr] /= 2;
        ans.push_back(ans[itr]);
    }

    if (ans.size() < K) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int n : ans) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}