#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;

int n;

long long m;

int ans[N];

int main() {
    cin >> n >> m;
    int cur = 1, l = 0, r = n - 1;
    --m;
    for (int i = n - 2; i >= -1; --i) {
        if (i == -1 || (m >> i & 1)) {
            ans[r] = cur;
            --r;
        } else {
            ans[l] = cur;
            ++l;
        }
        ++cur;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}