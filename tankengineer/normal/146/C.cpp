#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
char a[N], b[N];

int main() {
    scanf("%s%s", a, b);
    int l = strlen(a);
    int cnt47 = 0, cnt74 = 0;
    for (int i = 0; i < l; ++i) {
        if (a[i] == '4' && b[i] == '7') {
            ++cnt47;
        }
        if (a[i] == '7' && b[i] == '4') {
            ++cnt74;
        }
    }
    printf("%d\n", max(cnt47, cnt74));
    return 0;
}