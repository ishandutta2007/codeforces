#include<bits/stdc++.h>
using namespace std;

int main(){
    int z, k, p = 0, a = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++){
        a = k;
        cin >> k;
        if (k == a && k != 3){
            k = 0;
        }
        if (k != a && k == 3){
            k -= a;
        }
        if (k == 0){
            p++;
        }
    }
    cout << p;
}