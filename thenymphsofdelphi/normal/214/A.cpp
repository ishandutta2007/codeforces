#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    for (a = 0; a <= 1000; a++){
        for (b = 0; b <= 1000; b++){
            if (a * a + b == n && a + b * b == m){
                cnt++;
            }
        }
    }
    cout << cnt;
}