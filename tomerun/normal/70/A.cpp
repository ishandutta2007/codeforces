#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n-1; ++i) {
        ans *= 3;
        ans %= 1000003;
    }
    cout << ans << endl;
    return 0;
}