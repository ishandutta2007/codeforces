#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> take;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            take.push_back(i);
            break;
        }
    }
    for (int i = 0; i < (int) take.size(); i++) {
        int where = take[i];
        for (int j = 1; j <= k; j++) {
            if (take[i] + j < n && s[take[i] + j] == '*') {
                where = take[i] + j;
            }
        }
        if (where != take[i]) take.push_back(where);
    }
    cout << take.size() << "\n";
}

int main() {
    int tt;
    cin >> tt;
    while (tt--)
        test_case();
    return 0;
}