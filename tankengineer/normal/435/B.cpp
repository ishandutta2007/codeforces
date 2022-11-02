#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

char a[N];

int main() {
    int k;
    scanf("%s%d", a, &k);
    int l = strlen(a);
    for (int i = 0; i < l; ++i) {
        int best = i;
        for (int j = i + 1; j < l && j <= i + k; ++j) {
            if (a[j] > a[best]) {
                best = j;
            }
        }
        if (best != i) {
            for (int j = best; j > i; --j) {
                swap(a[j], a[j - 1]);
                --k;
            }
        }
    }
    printf("%s\n", a);
    return 0;
}