#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x % 2 == 1){
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
}