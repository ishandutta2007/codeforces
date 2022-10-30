#include<stdio.h>
#include <iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    int res = 0, cnt1 = 1, cnt2 = 1;
    while (res <= n) {
        res += cnt2;
        cnt1++;
        cnt2 += cnt1;
//        cout << res << ' ' << cnt1 << ' ' << cnt2 << endl;
    }
    cout << cnt1 - 2;
}