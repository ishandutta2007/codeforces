#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    int val[n];
    pair <string, string> a[n];
    string t;
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if (a[i].second.length() < a[i].first.length()) val[i] = 1;
        else val[i] = 0;
    }
    for (int i = 0; i < m; i++){
        cin >> t;
        for (int j = 0; j < n; j++){
            if (a[j].first == t || a[j].second == t){
                if (val[j]) cout << a[j].second;
                else cout << a[j].first;
                cout << " ";
            }
        }
    }
}