#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N], ma = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    for (int i = 0; i < N; ++i) {
        if (a[i] == ma) continue;

        vector<int> stack;
        int j;
        for (j = i; j < N && a[j] < ma; ++j) {
            if (!stack.empty() && stack.back() == a[j]) {
                stack.pop_back();
            } else if (!stack.empty() && stack.back() < a[j]) {
                cout << "NO" << endl;
                return 0;
            } else {
                stack.push_back(a[j]);
            }
        }

        if (!stack.empty()) {
            cout << "NO" << endl;
            return 0;
        }

        i = j;
    }

    cout << "YES" << endl;
    return 0;
}