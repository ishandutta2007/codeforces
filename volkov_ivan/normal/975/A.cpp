#include <iostream>
#include <set>

using namespace std;

int main() {
    set <string> ans;
    set <char> now;
    int n;
    cin >> n;
    string s, add;
    for (int i = 0; i < n; i++) {
        now.clear();
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            now.insert(s[j]);
        }
        add = "";
        for (char elem : now) add += elem;
        ans.insert(add);
    }
    cout << ans.size() << endl;
    return 0;
}