#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n, i, count = 1, a[100000];
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    for (i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            count++;
        }
    }
    cout << count;
}