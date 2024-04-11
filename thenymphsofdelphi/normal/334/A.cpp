#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, val;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = n * i;
    }
    vector <int> b;
    for (int i = 0; i < n; i++){
        b.push_back(i);
    }
    for (int i = 0; i < n; i++){
        val = b[0];
        for (int i = 0; i < n; i++){
            cout << a[i] + b[i] + 1 << " ";
        }
        b.erase(b.begin());
        b.push_back(val);
        cout << endl;
    }
}