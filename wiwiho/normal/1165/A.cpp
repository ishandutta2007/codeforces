#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    string number;
    cin >> number;

    int ans = 0;
    for(int i = n - 1; i > n - x - 1; i--){
        if(i != n - y - 1 && number[i] == '1'){
            ans++;
        }
    }

    if(number[n - y - 1] == '0'){
        ans++;
    }

    cout << ans << "\n";
    
    return 0;
}