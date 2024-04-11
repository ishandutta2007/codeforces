#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int T; cin >> T;

    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A;
        int res = K / 2;
        for(int i = K + 1; i <= N; i++) {
            A.emplace_back(i);
        }
        int cur = K-1;
        while(res -- > 0) {
            A.push_back(cur);
            cur--;
        }

        cout << A.size() << "\n";
        for(auto &a: A)
            cout << a << " ";
        cout << "\n";
    }
}