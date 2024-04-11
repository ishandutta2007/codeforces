#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0) return 0;
    }
    for (int i = 7; i * i <= n; i += 6){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n, n2, k, a[20], cnt = 0;
    cin >> n >> k;
    n2 = n;
    for (int i = 2; i <= 100000; i++){
        while (isprime(i) && n % i == 0){
            a[cnt] = i;
            cnt++;
            n /= i;
        }
    }
    if (cnt < k){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < k - 1; i++){
        cout << a[i] << " ";
        n2 /= a[i];
    }
    cout << n2;
}