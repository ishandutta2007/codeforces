#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, m, x;
    cin >> n >> m;
    x = n / m;
    if (x % 2 == 1){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}