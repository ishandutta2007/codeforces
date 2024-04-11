#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include <queue>
#define LL long long

using namespace std;

LL res[1000100];

int main () {
    LL n, cnt = 0;
    cin >> n;
    LL t = (3 - n % 3) % 3;
    res[0] = 0;
    for (int i = 1; i <= 1e6; i++) {
        res[i] = res[i - 1] + i * 3 - 1;
        if (res[i] > n) {
            break;
        }
        if (i % 3 == t) cnt++;
    }
    cout << cnt << endl;
}