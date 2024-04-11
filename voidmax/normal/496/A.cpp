#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define x first
#define y second
#define point pair <int, bool>
#define dir second
#define mp make_pair
#define int long long
using namespace std;

int n;
int ans = 0;
int minans = 1e9;
int arr[100];

main() {
    //freopen("learning.in", "r", stdin);
    //freopen("learning.out", "w", stdout);
    cin >> n;
    cin >> arr[0];
    For (i, 1, n) {
        cin >> arr[i];
        ans = max(abs(arr[i - 1] - arr[i]), ans);
    }
    For (i, 1, n - 1) {
        if (minans > max(ans, abs(arr[i - 1] - arr[i + 1]))) {
            minans = max(ans, abs(arr[i - 1] - arr[i + 1]));
        }
    }
    cout << minans << endl;
}