#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int a[n], ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1){
            if (x == 0){
                ans++;
            }
            else{
                x--;
            }
        }
        else{
            if (x == 0 && y == 0){
                ans++;
            }
            else if (y == 0){
                x--;
            }
            else{
                y--;
            }
        }
    }
    cout << ans;
}