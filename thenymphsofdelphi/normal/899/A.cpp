#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 1){
            a++;
        }
        else{
            b++;
        }
    }
    int ans = 0, mn = min(a, b);
    ans += mn;
    a -= mn;
    b -= mn;
    ans += a / 3;
    cout << ans;
}