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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int tol = 0;
        int ptol = 1;
        int curr = 0;
        int ans = 1;
        int cmp = 0;
        for(int i=1;i<n;i++) {
            if(a[i]<cmp) {
                ++curr;
                if(curr==ptol) {
                    ptol = tol;
                    tol = 0;
                    curr = 0;
                    cmp = 0;
                    ++ans;
                }
                ++tol;
            }
            else {
                ++tol;
            }
            cmp = a[i];
        }
        cout << ans << endl;
    }
}