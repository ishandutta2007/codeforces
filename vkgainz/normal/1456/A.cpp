#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string a;
        cin >> a;
        int x,y; cin >> x >> y;
        ll ans[n+1];
        memset(ans, 0, sizeof(ans));
        //ans[x] is starting
        for(int i=n;i>=1;i--) {
            if(i+k>n) {
                if(a[i-1]=='0') ans[i] = x;
                else ans[i] = 0;
            }
            else {
                if(a[i-1]=='0') ans[i] = x+ans[i+k];
                else ans[i] = ans[i+k];
            }
        }
        int numBef = 0;
        for(int i=1;i<=n;i++) {
            if(i<p) {
                if(a[i-1]=='1') ++numBef;
                ans[i]+=1LL*1e12;
                continue;
            }
            ans[i]+=(i-p)*1LL*y;
            if(a[i-1]=='1') ++numBef;
        }
        ll ret = 1e15;
        for(int i=1;i<=n;i++)
            ret = min(ret, ans[i]);
        cout << ret << "\n";
    }
}