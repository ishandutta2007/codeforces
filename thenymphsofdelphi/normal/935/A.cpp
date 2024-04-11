#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0, j;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            j = n / i;
            if (j > 1) cnt++;
        }
    }
    cout << cnt;
}