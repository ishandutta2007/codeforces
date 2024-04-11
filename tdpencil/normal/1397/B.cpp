#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);

    int mx = 0;
    for(int &i : a){
        scanf("%d", &i);
        mx = max(mx, i);
    }

    sort(a.begin(), a.end());

    if(n >= 40) {
        ll sum = 0;
        for(int i : a) {
            sum += i - 1; 
        }

        printf("%lld" ,sum);
    } else {
        ll t = 1;
        while(pow(t,n-1)<mx) {
            t++;
        }
        ll x = 1e18;
        for(int i = 1; i <= t; i++) {
            ll ans = 0;
            ll pw = 1;
            for(int &j : a) {
                ans += abs(j - pw);
                pw *= i;
            }
            x = min(x, ans);
        }

        printf("%lld", x);
    }
}