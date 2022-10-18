#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    vector <int> b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            b.push_back(a[i - 1]);
        }
    }
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
}