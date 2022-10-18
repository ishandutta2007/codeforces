#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a[7], i = 0, cnt = 0;
    cin >> n;
    for (int j = 0; j < 7; j++){
        cin >> a[j];
    }
    while (cnt < n){
        cnt += a[i];
        i = (i + 1) % 7;
    }
    if (i == 0){
        i = 7;
    }
    cout << i;
}