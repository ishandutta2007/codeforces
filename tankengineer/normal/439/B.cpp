#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, x, a[N];

long long ans = 0;

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        ans += (long long)a[i] * x;
        if (x > 1) {
            --x;
        }
    }
    cout << ans << endl;
    return 0;
}