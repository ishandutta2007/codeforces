#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, mdis;
    cin >> n >> x >> y;
    x--;
    y--;
    string a;
    cin >> a;
    if (a[x] == a[y]){
        cout << 0;
        return 0;
    }
    /*
    mdis = n;
    for (int i = 0; i < n; i++){
        if (a[i] == a[x]){
            mdis = min(mdis, abs(i - y));
        }
        else{
            mdis = min(mdis, abs(i - x));
        }
    }
    cout << mdis;
    */
    cout << 1;
}