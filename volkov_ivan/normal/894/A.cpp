#include <iostream>

using namespace std;

int main() {
    string s;
    int ans = 0;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}