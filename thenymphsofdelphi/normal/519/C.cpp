#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, ans = 0;
    cin >> a >> b;
    if (a > b){
        swap(a, b);
    }
    while (a > 0 && b >= 2){
        ans++;
        a--;
        b -= 2;
        if (a > b){
            swap(a, b);
        }
    }
    cout << ans;
}