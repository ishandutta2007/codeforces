#include<bits/stdc++.h>
using namespace std;

int gcd(int n, int m){
    if (n > m){
        swap(n, m);
    }
    if (n == 0) return m;
    return gcd(m % n, n);
}

int main(){
    int n, m;
    cin >> n >> m;
    int p = gcd(n, m);
    bool ck[p];
    memset(ck, 0, sizeof(ck));
    int n2, x;
    cin >> n2;
    for (int i = 0; i < n2; i++){
        cin >> x;
        x %= p;
        ck[x] = 1;
    }
    cin >> n2;
    for (int i = 0; i < n2; i++){
        cin >> x;
        x %= p;
        ck[x] = 1;
    }
    for (int i = 0; i < p; i++){
        if (!ck[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}