#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, a[n];
    for (int i = 0; i < n; i++){
        cin >> x;
        while (x % 2 == 0){
            x /= 2;
        }
        while (x % 3 == 0){
            x /= 3;
        }
        a[i] = x;
    }
    for (int i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}