#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N;
        cin >> N;
        set<int> A;
        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;
            A.insert(a);
        }

        int ans = 0;
        int ma = *A.rbegin();
        if (ma % 2 == 0 && ma % 3 == 0 && ma % 5 == 0 &&
            A.count(ma / 2) && A.count(ma / 3) && A.count(ma / 5)) {
            ans = ma / 2 + ma / 3 + ma / 5;
        }

        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            if (A.empty()) break;
            ma = *A.rbegin();
            sum += ma;

            for (auto itr = A.begin(); itr != A.end();) {
                if (ma % *itr == 0) {
                    itr = A.erase(itr);
                } else {
                    ++itr;
                }
            }
        }
        ans = max(ans, sum);
        cout << ans << endl;
    }
    return 0;
}