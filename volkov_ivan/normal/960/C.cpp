#include <iostream>
#include <vector>

using namespace std;

const int diff = 1e9 + 7;

int main() {
    int x, d;
    cin >> x >> d;
    long long now = 1;
    vector <long long> ans;
    for (int i = 31; i >= 0; i--) {
        if ((x & (1 << i)) != 0) {
            for (int j = 0; j < i; j++) ans.push_back(now);
            now += diff;
            ans.push_back(now);
            now += diff;
        }
    }
    cout << ans.size() << endl;
    for (long long elem : ans) cout << elem << ' ';
    cout << endl;
    return 0;
}