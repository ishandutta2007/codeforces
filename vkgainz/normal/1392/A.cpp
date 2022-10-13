#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int m = 0;
        for(int i=0;i<n-1;i++)
            m+=(a[i+1]==a[i]);
        if(m==n-1 && n!=1)
            cout << n << endl;
        else
            cout << 1 << endl;
    }
}