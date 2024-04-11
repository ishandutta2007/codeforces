#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.length();

    string T = S;
    vector<int> ans;
    int now = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (now == 0) {
            if (T[i] == 'a') {
                ans.push_back(1);
                T.pop_back();
                reverse(T.begin(), T.end());
                now = 1 - now;
            } else {
                ans.push_back(0);
                T.pop_back();
            }
        } else {
            if (T[0] == 'b') {
                ans.push_back(1);
                T.erase(T.begin());
                reverse(T.begin(), T.end());
                now = 1 - now;
            } else {
                ans.push_back(0);
                T.erase(T.begin());
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}