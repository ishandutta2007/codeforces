#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n, t, i;
    cin >> n >> t;
    string a, b;
    cin >> a;
    b = a;
    while (t--){
        for (i = 1; i < n; i++){
            if (a[i] == 'G' && a[i - 1] == 'B'){
                b[i - 1] = 'G';
                b[i] = 'B';
            }
            else{
                b[i] = a[i];
            }
        }
        a = b;
    }
    for (i = 0; i < n; i++){
        cout << a[i];
    }
}