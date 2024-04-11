#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, i, sum;
    cin >> n >> x;
    sum = n;
    for (i = 1; i <= 11; i++){
        if (sum % 10 == x || sum % 10 == 0){
            cout << i;
            return 0;
        }
        sum += n;
    }
}