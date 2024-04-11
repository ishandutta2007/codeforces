#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

const int BASE = 1e9 + 7;

int n, res;
string s;
int cnt[5];

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cnt[0]++; else
        if (s[i] == 'C') cnt[1]++; else
        if (s[i] == 'G') cnt[2]++; else
        cnt[3]++;   
    }
    int mx = -1, k = 0;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            k = 0;
        }
        if (cnt[i] == mx) k++;
    }
    int res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 1LL * k) % BASE;
    }
    printf("%d\n", res);
}