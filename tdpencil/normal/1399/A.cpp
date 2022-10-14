#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        bool f = 0;
        for(int i =0 ; i < n; i++)
            if(i<n-1&&a[i+1]-a[i]>1)
                f=1;
        cout << (f?"NO\n":"YES\n");
    }
}