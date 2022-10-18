#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++){
        if (a[a[a[i]]] == i){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}