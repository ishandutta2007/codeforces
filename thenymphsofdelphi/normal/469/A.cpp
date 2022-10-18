#include<iostream>
using namespace std;

int main(){
    int n, i, m, x;
    cin >> n;
    bool a[n];
    for (i = 0; i < n; i++){
        a[i] = false;
    }
    cin >> m;
    for (i = 0; i < m; i++){
        cin >> x;
        a[x - 1] = true;
    }
    cin >> m;
    for (i = 0; i < m; i++){
        cin >> x;
        a[x - 1] = true;
    }
    for (i = 0; i < n; i++){
        if (!a[i]){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
}