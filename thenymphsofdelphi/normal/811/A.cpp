#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int cnt = 1, turn = 0;
    while (1){
        if (turn == 0){
            if (a < cnt){
                cout << "Vladik";
                return 0;
            }
            a -= cnt;
        }
        else{
            if (b < cnt){
                cout << "Valera";
                return 0;
            }
            b -= cnt;
        }
        cnt++;
        turn = 1 - turn;
    }
}