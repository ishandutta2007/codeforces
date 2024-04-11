#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if ((n & 1) && (a[0] & 1) && (a[n - 1] & 1)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}