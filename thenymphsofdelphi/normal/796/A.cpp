#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    m--;
    int x, mindis = 100000000;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x != 0 && x <= k){
            mindis = min(mindis, abs(i - m));
        }
    }
    cout << mindis * 10;
}