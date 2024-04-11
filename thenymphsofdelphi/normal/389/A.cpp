#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = a[0];
    for (int i = 1; i < n; i++){
        ans = gcd(ans, a[i]); 
    }
    cout << ans * n;
}