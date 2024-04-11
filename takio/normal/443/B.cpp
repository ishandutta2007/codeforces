#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

char s[410];

int main () {
    int k, res = 0;
    cin >> s >> k;
    int l = strlen (s);
    if (l * 2 <= k) {cout << (k + l)/ 2 * 2;return 0;}
    for (int i = 0; i < l; i++)
        for (int j = i; j < l + k; j++)
        if (j + (j - i + 1) < k + l)
        {
//            cout << i << ' ' << j << ' ' <<  i + 2 * (j - i + 1) << endl;
            int len = j - i + 1;
            for (int o = i; o <= j; o++)
                if (o + len >= l || s[o] == s[o + len])continue;
                else {
//                    cout << i << ' ' << j << ' ' <<s[o] << ' ' << s[o+len] << endl;
                    goto x;}

            if (res < len * 2){
                res = len * 2;
            }
//            cout << i << ' ' << j << ' ' << res << endl;
            x:;
        }
    cout << res;
}