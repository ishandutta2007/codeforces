#include <bits/stdc++.h>

using namespace std;

int solve(string a, string b) {
    int n = (int)a.length();
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return -1;
        }
    }
    int operations = 0;
    for (char c = 'a'; c <= 'z' && a != b; c++) {
        char target = 'z' + 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == c && a[i] < b[i]) {
                target = min(target, b[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == c && a[i] < b[i]) {
                a[i] = target;
            }
        }
        if (target <= 'z') {
            operations++;
        }
    }
    return operations;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}