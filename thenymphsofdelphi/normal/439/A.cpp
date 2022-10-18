#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int x, sum = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    if (sum + (n - 1) * 10 > s){
        cout << "-1";
        return 0;
    }
    s -= sum;
    cout << s / 5;
}