#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main () {
    int n, v, a[110], ai = 0;
    cin >> n >> v;
    for (int i = 1; i <= n; i++){
        int k, flag = 1, q;
        cin >> k;
        for (int j = 1; j <= k; j++){
            cin >> q;
            if (q < v) flag = 0;
        }
        if (!flag) a[++ai] = i;
    }
    cout << ai << endl;
    for (int i = 1; i <= ai; i++){
        if (i != 1) cout << ' ';
        cout << a[i];
    }
}