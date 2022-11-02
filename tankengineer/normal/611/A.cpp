#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int num, mk, wk, cm, cd, cw;
    char key[55];
    scanf("%d%*s%s", &num, key);
    if (key[0] == 'w') {
        mk = -1, wk = num - 1;
    } else {
        mk = num - 1, wk = -1;
    }   
    cm = 0, cd = 0, cw = 4;
    int ans = 0;
    const int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (cm < 12) {
        if (cd == mk || cw == wk) {
            ++ans;
        }
        ++cd;
        ++cw;
        cw %= 7;
        if (cd == days[cm]) {
            ++cm;
            cd = 0;
            if (cm == 12) {
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}