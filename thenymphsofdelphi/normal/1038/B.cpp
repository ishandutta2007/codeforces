#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n <= 2){
        cout << "No";
        return 0;
    }
    cout << "Yes\n1 ";
    if (n & 1){
        cout << (n + 1) / 2 << endl << n - 1 << ' ';
        for (int i = 1; i <= n; i++){
            if (i != (n + 1) / 2){
                cout << i << ' ';
            }
        }
    }
    else{
        cout << n / 2 << endl << n - 1 << ' ';
        for (int i = 1; i <= n; i++){
            if (i != n / 2){
                cout << i << ' ';
            }
        }
    }
}