#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int ans = 0;
    long long a, b;
    cin >> a >> b;
    for (int len = 2; (1ll << len - 1) <= b; ++len) {
        for (int zero = 0; zero < len - 1; ++zero) {
            long long num = (1ll << len) - 1 - (1ll << zero);
            if (num >= a && num <= b) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}