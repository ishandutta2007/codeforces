#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, i, t;
    cin >> n >> m;
    m = 240 - m;
    for (i = 1; i <= 10; i++){
        t = i * (i + 1) / 2 * 5;
        if (t > m){
            cout << min(i - 1, n);
            return 0;
        }
    }
}