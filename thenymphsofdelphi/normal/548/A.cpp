#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, m;
    string s;
    cin >> s >> k;
    n = s.length();
    if (n % k != 0){
        cout << "NO";
        return 0;
    }
    m = n / k;
    string a[k], b[k];
    for (int i = 0; i < k; i++){
        a[i] = s.substr(i * m, m);
        b[i] = a[i];
        reverse(b[i].begin(), b[i].end());
        if (a[i] != b[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}