#include<bits/stdc++.h>
using namespace std;

long a[100000], b[100000];

int main(){
    long n, k, t = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i != 0){
            b[i - 1] = a[i] - a[i - 1];
        }
    }
    for (int i = 0; i < n - 1; i++){
        if (b[i] > k){
            t = 1;
        }
        else{
            t++;
        }
    }
    cout << t;
}