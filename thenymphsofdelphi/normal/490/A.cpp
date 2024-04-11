#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, na = 0, nb = 0, nc = 0, nf;
    int a[5000], b[5000], c[5000], x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 1){
            a[na] = i + 1;
            na++;
        }
        else if (x == 2){
            b[nb] = i + 1;
            nb++;
        }
        else{
            c[nc] = i + 1;
            nc++;
        }
    }
    nf = min(na, nb);
    nf = min(nf, nc);
    cout << nf << endl;
    for (int i = 0; i < nf; i++){
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
}