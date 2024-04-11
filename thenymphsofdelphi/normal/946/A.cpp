#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, i, sum = 0;
    for (i = 0; i < n; i++){
        cin >> x;
        sum += abs(x);
    }
    cout << sum;
}