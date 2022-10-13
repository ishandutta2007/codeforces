#include <bits/stdc++.h>
using namespace std;
int n, x, y;

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        cin >> x >> y >> n;
        int k = (n-y)/x;
        k*=x;
        k+=y;
        cout << k << endl;
    }
}