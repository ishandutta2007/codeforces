#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = ceil(n / 2.0); i <= n; i++){
        if (i % m == 0){
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}