#include<bits/stdc++.h>
using namespace std;

int a[1000010];

int main(){
    int n, m, x = 1, y;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> y;
        y += x - 1;
        for (int j = x; j <= y; j++){
            a[j] = i;
        }
        x = y + 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        cout << a[x] << endl;
    }
}