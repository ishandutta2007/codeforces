#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 10;
int a[N];
int or_suff[N], or_pref[N];

int f(int a, int b) {
    return (a | b) - b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        or_pref[i + 1] = or_pref[i] | a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        or_suff[i] = or_suff[i + 1] | a[i];
    }

    int best_pivot = 0;
    int best_value = 0;
    for (int i = 0; i < n; i++) {
        int current_value = f(a[i], or_pref[i] | or_suff[i + 1]);
        if (current_value > best_value) {
            best_pivot = i;
            best_value = current_value;
        }
    }
    
    printf("%d ", a[best_pivot]);
    for (int i = 0; i < n; i++) {
        if (i == best_pivot) {
            continue;
        }
        printf("%d ", a[i]);
    }
    puts("");

    return 0;
}