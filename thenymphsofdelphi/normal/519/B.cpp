#include<bits/stdc++.h>
using namespace std;

const int N = 100000, M = 1000000001;
long a[N], b[N], c[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n - 2; i++){
        cin >> c[i];
    }
    b[n - 1] = M;
    c[n - 1] = M;
    c[n - 2] = M;
    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            cout << a[i] << endl;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++){
        if (b[i] != c[i]){
            cout << b[i] << endl;
            return 0;
        }
    }
}