#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct fruit {
    int a, b;
}f[3010];

bool cmp(fruit a, fruit b){
    return a.a < b.a;
}

int main () {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++){
        cin >> f[i].a >> f[i].b;
    }
    sort (f + 1, f + 1 + n, cmp);
    int d = 1, cnt1 = 0, cnt2 = 0, res = 0;
    for (int i = 1; i <= 3002; i++){
        while (f[d].a == i){
            cnt1 += f[d].b;
            d++;
        }
        int has = v;
        if (cnt2){
            if (cnt2 < v) res += cnt2, has -= cnt2;
            else res += v, has = 0;
        }

        if (cnt1 < has) res += cnt1, cnt1 = 0;
        else res += has, cnt1 -= has;

//        if (i <= 3)cout << res << ' ' << cnt1 << ' ' << cnt2 << endl;
        cnt2 = cnt1;
        cnt1 = 0;
    }
    cout << res;
}