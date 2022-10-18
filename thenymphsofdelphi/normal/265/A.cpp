#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length(), i = 0, j = 0;
    for (i = 0; i < m; i++){
        if (b[i] == a[j]){
            j++;
        }
    }
    cout << j + 1;
}