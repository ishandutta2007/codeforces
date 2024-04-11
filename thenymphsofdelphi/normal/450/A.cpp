#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double m;
    cin >> n >> m;
    int a[n], mx = -1, idx;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (ceil(a[i] / m) >= mx){
            mx = ceil(a[i] / m);
            idx = i;
        }
    }
    cout << idx + 1;
}