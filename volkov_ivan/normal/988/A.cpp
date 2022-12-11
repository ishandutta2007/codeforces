#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map <int, int> all;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        if (all.find(now) == all.end()) all[now] = i + 1;
    }
    if (all.size() < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cnt = 0;
    for (pair <int, int> elem : all) {
        if (cnt < k) cout << elem.second << ' ';
        cnt++;
    }
    return 0;
}