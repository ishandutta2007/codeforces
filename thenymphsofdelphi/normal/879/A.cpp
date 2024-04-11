#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, res = 0;
    cin >> n;
    while (n--){
        cin >> x >> y;
        while (x <= res){
            x += y;
        }
        res = x;
    }
    cout << res;
}