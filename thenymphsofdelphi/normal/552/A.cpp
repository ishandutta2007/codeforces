#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x1, y1, x2, y2, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        sum += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << sum;
}