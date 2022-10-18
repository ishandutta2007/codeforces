#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int pos1 = 0, pos2 = n - 1;
    while (a[pos1] < a[pos1 + 1]){
        pos1++;
    }
    while (a[pos2] < a[pos2 - 1]){
        pos2--;
    }
    for (int i = pos1 + 1; i <= pos2; i++){
        if (a[i] != a[i - 1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}