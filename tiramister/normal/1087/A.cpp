#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    string ans = "";
    while (!S.empty()) {
        if (S.length() % 2 == 0) {
            ans.push_back(S.back());
            S.pop_back();
        } else {
            ans.push_back(S.front());
            S.erase(S.begin());
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}