#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, x, now = 0, sum = 0;
    cin >> n;
    while (n--){
        cin >> x;
        if (x < 0 && now == 0){
            sum++;
        }
        else if (x < 0 && now != 0){
            now--;
        }
        else{
            now += x;
        }
    }
    cout << sum;
}