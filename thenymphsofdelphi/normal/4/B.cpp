#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int a[n], b[n], c[n];
    int s1 = 0, s2 = 0, ans;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        c[i] = a[i];
        s1 += a[i];
        s2 += b[i];
    }
    if (s < s1 || s > s2){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    ans = s1;
    int idx = 0;
    while (ans < s){
        if (s - ans <= b[idx] - a[idx]){
            c[idx] += s - ans;
            break;
        }
        c[idx] = b[idx];
        ans += b[idx] - a[idx];
        idx++;
    }
    for (int i = 0; i < n; i++){
        cout << c[i] << ' ';
    }
}