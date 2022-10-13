#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while(t--){ 
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
            int mx = 0;
            for(int i=0;i<n;i++) mx = max(mx,a[i]);
            int ans = -2;
            for(int i=0;i<n;i++) {
                if(a[i]==mx) {
                    if(i==0) {
                        if(a[i]>a[i+1]) ans = i;
                    }
                    else if(i==n-1){
                        if(a[i]>a[i-1]) ans = i;
                    }
                    else {
                        if(a[i]>a[i-1] || a[i]>a[i+1]) ans = i;
                    }
                }
            }
            cout << ans+1 << endl;

    }
}