#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int cntp[26], cnts[26];
char s[N], p[N];

int main() {
    scanf("%s%s", s, p);
    int l0 = strlen(s), l1 = strlen(p);
    for (int i = 0; i < l1; ++i) {
        ++cntp[p[i] - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < l0; ++i) {
        if (s[i] != '?') {
            ++cnts[s[i] - 'a'];
        }
        if (i - l1 + 1 >= 0) {
            ++ans;
            for (int j = 0; j < 26; ++j) {
                if (cnts[j] > cntp[j]) {
                    --ans;
                    break;
                }
            }
            if (s[i - l1 + 1] != '?') {
                --cnts[s[i - l1 + 1] - 'a'];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}