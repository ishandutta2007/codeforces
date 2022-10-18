#include<bits/stdc++.h>
using namespace std;

int a[5] = {500, 1000, 1500, 2000, 2500}, b[5], c[5], x, y, sum = 0;
long double t, u;

int main(){
    for (int i = 0; i < 5; i++){
        cin >> b[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> c[i];
        t = (1.0 - b[i] / 250.0) * a[i] - 50.0 * c[i];
        u = 0.3 * a[i];
        sum += (int)max(t + 0.1, u + 0.1);
    }
    cin >> x >> y;
    sum += 100 * x;
    sum -= 50 * y;
    cout << sum;
}