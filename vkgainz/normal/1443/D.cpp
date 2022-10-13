#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        bool work = true;
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) {
                ll tot = 0;
                for(int j=i+1;j<n;j++) {
                    if(a[j]<a[j-1]) {
                        tot+=a[j-1]-a[j];
                    }
                }
                if(tot>a[i-1]) work = false;
            }
        }
        if(work) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}