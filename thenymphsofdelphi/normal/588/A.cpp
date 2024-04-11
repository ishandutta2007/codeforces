#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y, mn = 101, sum = 0;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (y < mn){
            mn = y;
        }
        sum += x * mn;
    }
    cout << sum;
}