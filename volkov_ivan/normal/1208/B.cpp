#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    unordered_set <int> kek;
    bool good = 1;
    for  (int i = 0; i < n; i++) {
        cin >> a[i];
        if (kek.find(a[i]) != kek.end()) good = 0;
        kek.insert(a[i]);
    }
    if (good) {
        cout << 0 << endl;
        return 0;
    }
    int best = 0;
    unordered_set <int> left;
    for (int pref = 0; pref < n; pref++) {
        int tail = n - 1;
        unordered_set <int> right;
        int cnt = 0;
        while (left.find(a[tail]) == left.end() && right.find(a[tail]) == right.end()) {
            right.insert(a[tail]);
            tail--;
            cnt++;
        }
        best = max(best, cnt + pref);
        if (left.find(a[pref]) != left.end()) break;
        left.insert(a[pref]);
    }
    cout << n - best << endl;
    return 0;
}