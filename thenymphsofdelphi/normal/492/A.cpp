#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int i = 1;
    while (sum <= n){
        sum += i * (i + 1) / 2;
        i++;
    }
    cout << i - 2;
}