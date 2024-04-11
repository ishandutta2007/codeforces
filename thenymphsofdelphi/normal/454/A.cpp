#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    m = n / 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (abs(m - i) + abs(m - j) <= m){
                cout << "D";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }
}