#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    double avg = (n * 9) / 2.0;
    if (avg <= s){
        cout << 0;
        return 0;
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans++;
        s += 5 - a[i];
        if (avg <= s){
            cout << ans;
            return 0;
        }
    }
}