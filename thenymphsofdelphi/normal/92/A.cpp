#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int p = n * (n + 1) / 2;
    m %= p;
    for (int i = 1; i <= n; i++){
        if (m < i){
            cout << m;
            return 0;
        }
        m -= i;
    }
    cout << m;
    return 0;
}