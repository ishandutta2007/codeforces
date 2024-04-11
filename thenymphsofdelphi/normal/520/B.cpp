#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    while (m > n){
        ans++;
        if (m % 2 == 0) m /= 2;
        else m++;
    }
    ans += n - m;
    cout << ans;
}