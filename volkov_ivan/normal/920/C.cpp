#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;

const int MAX_N = 2e5 + 7;

int main() {
    int n;
    string s;
    cin >> n;
    int arr[n], pref[n], arr2[n], pos[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
        arr2[i] = arr[i];
    }
    cin >> s;
    pref[0] = 0;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }
    int left, right;
    stable_sort(arr2, arr2 + n);
    for (int i = 0; i < n; i++) {
        pos[arr2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        left = i;
        right = pos[arr[i]];
        if (left > right) swap(left, right);
        if (pref[right] - pref[left] != right - left) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}