#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>
#define LL long long
using namespace std;

int main () {
    int n;
    LL l, r;
    cin >> n;
    while (n--) {
        cin >> l >> r;
        for (LL i = 0; i < 63; i++) {
            if ((l | (1LL << i)) <= r) l |= (1LL << i);
        }
        cout << l << endl;
    }
}