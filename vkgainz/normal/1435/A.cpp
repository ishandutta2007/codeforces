#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int b[n];
        for(int i=0;i<n/2;i++) b[i] = -a[n-i-1];
        for(int i=n/2;i<n;i++) b[i] = a[n-i-1];
        for(int i=0;i<n;i++) cout << b[i] << " ";
        cout << endl;
    }
}