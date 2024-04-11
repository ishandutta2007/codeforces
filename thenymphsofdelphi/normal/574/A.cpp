#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n);
    while (a[0] <= a[n - 1]){
        a[0]++;
        a[n-1]--;
        sort(a + 1, a + n);
        c++;
    }
    cout << c;
}