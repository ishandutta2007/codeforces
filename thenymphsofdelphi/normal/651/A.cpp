#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, cnt = 0;
    cin >> a >> b;
    if (a == 1 && b == 1){
        cout << 0;
        return 0;
    }
    while (a > 0 && b > 0){
        cnt++;
        if (a < b){
            a++;
            b -= 2;
        }
        else{
            b++;
            a -= 2;
        }
    }
    cout << cnt;
}