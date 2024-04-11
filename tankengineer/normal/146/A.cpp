#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[100005];

int main() {
    scanf("%*s%s", s);
    int l = strlen(s);
    bool ans = true;
    for (int i = 0; i < l; ++i) {
        if (s[i] != '4' && s[i] != '7') {
            ans = false;
        }
    }
    int sum = 0;
    for (int i = 0; i < l; ++i) {
        if (i < l / 2) {
            sum += s[i] - '0';
        } else {
            sum -= s[i] - '0';
        }
    }
    if (sum != 0) {
        ans = false;
    }
    puts(ans ? "YES" : "NO");
    return 0;
}