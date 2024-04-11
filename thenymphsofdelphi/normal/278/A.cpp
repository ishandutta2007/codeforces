#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, sum1 = 0, sum2, x, y;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> x >> y;
    if (x == y){
        cout << 0;
        return 0;
    }
    x--;
    y--;
    if (x > y){
        swap(x, y);
    }
    for (int i = x; i < y; i++){
        sum1 += a[i];
    }
    sum2 = sum - sum1;
    cout << min(sum1, sum2);
}