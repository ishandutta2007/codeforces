#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

int main () {
    int n, m, res = 0;
    cin >> n >> m;
    for (; ;) {
        n--;
        res++;
        if (res % m == 0) n++;
        if (n == 0) break;
    }
    cout << res << endl;
}