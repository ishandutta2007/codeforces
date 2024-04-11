#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0, cnv = 0;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (abs(x - y) & 1){
            cnv = 1;
        }
        sum1 += x;
        sum2 += y;
    }
    if (abs(sum1 - sum2) & 1){
        cout << -1;
        return 0;
    }
    if ((sum1 & 1) && (sum2 & 1) && !cnv){
        cout << -1;
        return 0;
    }
    if ((!(sum1 & 1)) && (!(sum2 & 1))){
        cout << 0;
        return 0;
    }
    cout << 1;
}