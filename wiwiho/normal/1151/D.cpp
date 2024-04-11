#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    std::vector<long long> b(n);
    std::vector<long long> c(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
    }

    std::sort(c.begin(), c.end(), std::greater<long long>());

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += c[i] * (i + 1) + b[i] * n - a[i]; 
    }

    std::cout << ans << "\n";

    return 0;
}