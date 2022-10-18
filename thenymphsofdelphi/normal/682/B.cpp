#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        if (a[i] >= t){
            t++;
        }
    }
    cout << t;
}