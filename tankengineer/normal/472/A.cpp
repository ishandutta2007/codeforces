#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000005;
bool isprime[N];

int main() {
    for (int i = 2; i < N; ++i) {
        if (!isprime[i]) {
            for (int j = i + i; j < N; j += i) {
                isprime[j] = true;
            }
        }
    }
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("%d %d\n", 4, n - 4);
    } else {
        for (int i = 2; i < n; ++i) {
            if (isprime[i] && isprime[n - i]) {
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
    return 0;
}