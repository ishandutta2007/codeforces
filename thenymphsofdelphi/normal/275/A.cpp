#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[5][5], x;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> x;
            a[i][j] += x;
            a[i - 1][j] += x;
            a[i + 1][j] += x;
            a[i][j - 1] += x;
            a[i][j + 1] += x;
        }
    }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            ///*
            if (a[i][j] & 1){
                cout << 0;
            }
            else{
                cout << 1;
            }
            //*/
        }
        cout << endl;
    }
}