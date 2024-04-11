#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1 || n == 2){
        cout << "1\n1";
        return 0;
    }
    if (n == 3){
        cout << "2\n1 3";
        return 0;
    }
    if (n == 4){
        cout << "4\n3 1 4 2";
        return 0;
    }
    cout << n << endl;
    for (int i = 1; i <= n; i += 2){
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
}