#include<bits/stdc++.h>
using namespace std;

vector <int> a, b;

int main(){
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x != y){
            cout << "rated";
            return 0;
        }
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            cout << "unrated";
            return 0;
        }
    }
    cout << "maybe";
}