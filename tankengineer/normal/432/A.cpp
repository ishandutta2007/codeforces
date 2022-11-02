#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a + k <= 5) {
            ++cnt;
        }
    }
    printf("%d\n", cnt / 3);
    return 0;
}