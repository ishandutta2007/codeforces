#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;

int next[N], mins[N], maxs[N];
char s[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    int i = 0, j = 0, k = 1;
    while (1 + j < l && s[j] == s[1 + j]) {
        ++j;
    }
    next[1] = j;
    for (int i = 2; i < l; ++i) {
        int len = k + next[k], ll = next[i - k];
        if (ll < len - i) {
            next[i] = ll;
        } else {
            j = max(0, len - i);
            while (i + j < l && s[j] == s[i + j]) {
                ++j;
            }
            next[i] = j;
            k = i;
        }
    }
    for (int i = 0; i < l; ++i) {
        mins[i] = l + 1, maxs[i] = -1;
    }
    for (int i = 1; i < l; ++i) {
        int ll = next[i];
        mins[ll] = min(mins[ll], i), maxs[ll] = max(maxs[ll], i);
    }
    int ans = 0;
    for (int i = l - 1; i > 0; --i) {
        if (mins[i] + i < l && maxs[i] + i == l) {
            ans = i;
            break;
        } else {
            mins[i - 1] = min(mins[i - 1], mins[i]);
        }
    }
    if (ans == 0) {
        printf("Just a legend\n");
    } else {
        s[ans] = '\0';
        printf("%s\n", s);
    }
    return 0;
}