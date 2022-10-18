#include<bits/stdc++.h>
using namespace std;

int main(){
    long long r, x1, y1, x2, y2;
    long double dis;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    dis = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
    long long ans = dis / (r * 2);
    if (2 * r * ans != dis) ans++;
    cout << ans;
}