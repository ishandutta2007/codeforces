#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long double average;
    int x, i, sum = 0;
    for (i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    average = sum / (n / 1.0);
    cout << fixed << setprecision(4) << average;
}