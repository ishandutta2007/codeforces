#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    string s, t;
    vector <int> ans;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int pos = -1;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == t[i]) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                cout << -1 << endl;
                return 0;
            }
            for (int j = pos - 1; j >= i; j--) {
                swap(s[j], s[j + 1]);
                ans.push_back(j);
            }
        }
    }
    cout << ans.size() << endl;
    for (int elem : ans) cout << elem + 1 << ' ';
    cout << endl;
    return 0;
}