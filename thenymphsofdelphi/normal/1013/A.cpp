#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n], suma = 0, sumb = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        sumb += b[i];
    }
    if (suma < sumb){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
}