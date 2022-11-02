#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s1[105], s2[105], s3[105];

int cnt[26];

void c(char *s, int cc) {
    for (int i = 0; s[i]; ++i) {
        cnt[s[i] - 'A'] += cc;
    }
}

int main() {
    scanf("%s%s%s", s1, s2, s3);
    c(s1, 1), c(s2, 1), c(s3, -1);
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] != 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}