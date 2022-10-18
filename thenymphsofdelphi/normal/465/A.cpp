#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int cnt = 0;
    a += '0';
    for (int i = 0; i <= n; i++){
        cnt++;
        if (a[i] == '0'){
            break;
        }
    }
    if (cnt == n + 1){
        cnt = n;
    }
    cout << cnt;
}