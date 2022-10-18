#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    int t; cin >> t;
    while (t--){
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n / 2; i++){
            ans += (long long)i * i * 8ll;
        }
        cout << ans << endl;
    }
}