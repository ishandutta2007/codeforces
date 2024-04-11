#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10], b[10];

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    for (int i = 0; i < m; i++){
        cin >> x;
        b[x] = 1;
    }
    for (int i = 0; i < n; i++){
        if (b[a[i]]){
            cout << a[i] << ' ';
        }
    }
}