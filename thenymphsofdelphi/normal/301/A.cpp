#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, cnt = 0, n, sum = 0, mn = -2000;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++){
        cin >> x;
        sum += abs(x);
        if (x <= 0){
            cnt++;
            mn = max(mn, x);
        }
        else{
            mn = max(mn, -x);
        }
    }
    if ((cnt % n) % 2 == 1){
        sum += 2 * mn;
        if (n % 2 == 1){
            sum -= 2 * mn;
        }
    }
    cout << sum;
}