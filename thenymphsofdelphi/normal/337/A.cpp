#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int m, n, i, a[50], ans = 997;
    cin >> m >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = m - 1; i < n; i++){
        if (a[i] - a[i - m + 1] < ans){
            ans = a[i] - a[i - m + 1];
        }
    }
    cout << ans;
}