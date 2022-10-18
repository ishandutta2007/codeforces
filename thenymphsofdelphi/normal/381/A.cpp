#include<bits/stdc++.h>
using namespace std;

int main(){
    int sz;
    cin >> sz;
    int a[sz];
    for (int i = 0; i < sz; i++){
        cin >> a[i];
    }
    int m = 0, n = 0, x = 0, y = sz - 1, turn = 0;
    while (x <= y){
        if (turn == 0){
            if (a[x] > a[y]){
                m += a[x];
                x++;
            }
            else{
                m += a[y];
                y--;
            }
        }
        else{
            if (a[x] > a[y]){
                n += a[x];
                x++;
            }
            else{
                n += a[y];
                y--;
            }
        }
        turn = 1 - turn;
    }
    cout << m << " " << n;
}