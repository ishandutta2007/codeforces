#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 1; cin >> n;
    for (int i = 2; i <= n; i++){
        ans = (ans * 3) % (1000000 + 3);
    }
    cout << ans;
}