#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n), b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n < 3){
        cout << "YES";
        return 0;
    }
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            ans++;
            b.push_back(i);
        }
    }
    if (ans > 3){
        cout << "NO";
        return 0;
    }
    if (ans < 3){
        cout << "YES";
        return 0;
    }
    if (abs(a[b[0]] - a[0]) == abs(a[b[1]] - a[0])){
        cout << "YES";
        return 0;
    }
    if (abs(a[b[0]] - a[b[1]]) == abs(a[b[1]] - a[0])){
        cout << "YES";
        return 0;
    }
    if (abs(a[b[0]] - a[0]) == abs(a[b[1]] - a[b[0]])){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}