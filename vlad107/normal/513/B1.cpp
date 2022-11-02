#include <bits/stdc++.h>

using namespace std;

const int N = 500;

int n, a[N];
long long k;

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin >> n >> k;
    int l = 0, r = n - 1;
    long long pw = 1;
    for (int i = 0; i < n - 1; i++) pw *= 2;
    for (int i = 1; i <= n; i++) {
        pw /= 2;
        if (k > pw) {
            k -= pw;
            a[r--] = i;
        } else {
            a[l++] = i;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
}