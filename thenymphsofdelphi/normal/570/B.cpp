#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a = n - m, b = m - 1;
    if (n == 1){
        cout << 1;
        return 0;
    }
    if (a == b){
        cout << m - 1;
        return 0;
    }
    if (a < b){
        cout << m - 1;
        return 0;
    }
    cout << m + 1;
}