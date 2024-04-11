#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main () {
    int n, k[110];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    int mn = 1e9;
    for(int i = 1; i <= n; i++){
        int sum = 15 * k[i];
        for(int j = 1; j <= k[i]; j++){
            int m;
            cin >> m;
            sum += m * 5;
        }
        mn = min (sum, mn);
    }
    cout << mn;
}