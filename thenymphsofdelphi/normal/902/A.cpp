#include<bits/stdc++.h>
using namespace std;

bool ck[200];

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        for (int j = a; j < b; j++){
            ck[j] = 1;
        }
    }
    for (int i = 0; i < m; i++){
        if (!ck[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}