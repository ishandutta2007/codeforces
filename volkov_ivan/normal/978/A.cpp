#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    vector <int> ans;
    set <int> all;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (all.find(a[i]) == all.end()) {
            ans.push_back(a[i]);
            all.insert(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}