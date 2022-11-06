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
char arr[2000];
string minans = "\\";

main() {
    //freopen("learning.in", "r", stdin);
    //freopen("learning.out", "w", stdout);
    cin >> n;
    For (i, 0, n) {
        char a;
        cin >> a;
        arr[i] = a;
        arr[i + n] = a;
    }
    For (i, 0, 10) {
        For (q, 0, n * 2) {
            ++arr[q];
            if (arr[q] == '9' + 1) {
                arr[q] = '0';
            }
        }
        For (q, 0, n) {
            string ans = "";
            For (j, 0, n) {
                ans += arr[q + j];
            }
            if (minans > ans) {
                minans = ans;
            }
        }
    }
    cout << minans;
}