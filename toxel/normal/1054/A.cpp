#include<bits/stdc++.h>

int main(){
    int x, y, z, t1, t2, t3;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
    int ans1 = std::abs(x - y) * t1;
    int ans2 = std::abs(z - x) * t2 + std::abs(y - x) * t2 + 3 * t3;
    puts(ans1 < ans2 ? "NO" : "YES");
    return 0;
}