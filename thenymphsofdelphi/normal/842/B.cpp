#include<bits/stdc++.h>
using namespace std;
#define double long double

int main(){
    int r, d, n, x, y, t, cnt = 0;
    double tmp;
    cin >> r >> d >> n;
    while (n--){
        cin >> x >> y >> t;
        tmp = sqrt(1.0 - 1.0 + x * x + y * y);
        if (tmp + t <= r && tmp - t >= r - d){
            cnt++;
        }
    }
    cout << cnt;
}