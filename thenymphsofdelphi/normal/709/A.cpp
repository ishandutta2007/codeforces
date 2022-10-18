#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, b, d, x, cnt = 0, ans = 0;
    cin >> n >> b >> d;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x > b){
            continue;
        }
        cnt += x;
        if (cnt > d){
            cnt = 0;
            ans++;
        }
    }
    cout << ans;
}