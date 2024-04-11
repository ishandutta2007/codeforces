#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int t[1000100];

const int maxn = 1e6;

int main () {
    int n, flag = 1,x;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &x);
        t[x]++;
    }
    int cnt = 0;
    cout << n << endl;
    for (int i = 1; i <= maxn; i++){
        if (t[i] && !t[(int)(maxn - i + 1)]){
            if (flag) flag = 0;
            else printf (" ");
            printf ("%d", (int)maxn - i + 1);
            cnt++;
        }
    }
//    cout << cnt << endl;
    int i = 1;
    while(cnt < n){
            while(t[i] || t[(int)(maxn - i + 1)])i++;
            if (flag) flag = 0;
            else printf (" ");
            printf ("%d %d", i, (int)(maxn - i + 1));
            i++;
            cnt += 2;
    }
}