#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    // let even be the first?
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), [&](auto i, auto j) {return i % 2 < j % 2;});
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(gcd(a[i], 2 * a[j]) > 1) ++ans;
            }
        }
        cout << ans << '\n';
    }
}