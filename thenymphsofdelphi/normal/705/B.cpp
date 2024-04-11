#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 0, n, x;
    cin >> n;
    while (n--){
        cin >> x;
        t  = (t + x - 1) % 2;
        if (t == 0){
            t = 2;
        }
        cout << t << endl;
    }
}