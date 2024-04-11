#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ans(3);
    if (N % 3 == 0) {
        ans = {1, 1, N - 2};
    } else {
        ans = {1, 2, N - 3};
    }

    for (int i = 0; i < 3; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}