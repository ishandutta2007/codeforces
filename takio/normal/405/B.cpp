#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

char c[3010];

int main () {
    int n, flag = 1, t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        if (c[i] != '.' && flag) {
            flag = 0;
            if (c[i] == 'L')t = 1;
            else t = 2;
        }
    }
    if (t == 0) {
        cout << n;
        return 0;
    }
    int res;
    if (t == 1) {
//            cout << 'x';
        res = 0;
        int i = 1;
        while (c[i] != 'L') i++;
        int e = i, f;
        while (1){
//            cout << i << ' ' << res << endl;
            while (c[i] != 'R' && i <= n) i++;
            f = i;
            res += i - e - 1;
            if (i > n) break;
            while (c[i] != 'L' && i <= n) i++;
            if (i > n) break;
            e = i;
            if ((e - f) % 2 == 0) res++;
        }
    }
    else {
        res = 0;
        int i = 1;
        while (c[i] != 'R') i++;
        res += i - 1;
        int f = i, e;
        while (1){
//            cout << i << ' ' << res << endl;
            while (c[i] != 'L' && i <= n) i++;
            e = i;
            if (i > n) break;
            if ((e - f) % 2 == 0) res++;
            while (c[i] != 'R' && i <= n) i++;
            res += i - e - 1;
            f = i;
            if (i > n) break;
        }
    }
    cout << res;
}