#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long sum = 0, t = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++){
        t += a[i];
        if (t * 2 >= sum){
            cout << i + 1;
            return 0;
        }
    }
}