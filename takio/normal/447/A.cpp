#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int hs[330];

int main () {
    int p, n, res = -1, a, flag = 1;
    cin >> p >> n;
    for (int i = 1; i <= n; i++){
        cin >> a;
        if (flag)
        if (!hs[a % p]){
            hs[a % p]++;
        }
        else {
            flag = 0;
            res = i;
        }
    }
    cout << res;
}