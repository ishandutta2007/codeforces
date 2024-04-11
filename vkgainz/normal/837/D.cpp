#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int dp[205][5005]; //k by powers of 5
int main() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) {
        ll x; cin >> x;
        while(x%2==0) {
            x/=2;
            ++a[i].f;
        }
        while(x%5==0) {
            x/=5;
            ++a[i].s;
        }
    }
    for(int numChoose=0;numChoose<=k;numChoose++) {
        for(int pow=0;pow<=5000;pow++) {
            if(pow==0) dp[numChoose][pow] = 0;
            else dp[numChoose][pow] = -100000;
        }
    }
    for(int i=0;i<n;i++) {
        int temp[205][5005];
        for(int numChoose=1;numChoose<=k;numChoose++) {
            for(int pow=0;pow<=5000;pow++) {
                if(a[i].s<=pow) {
                    temp[numChoose][pow] = max(dp[numChoose][pow],dp[numChoose-1][pow-a[i].s]+a[i].f);
                }
            }
        }
        for(int numChoose=1;numChoose<=k;numChoose++) {
            for(int pow=0;pow<=5000;pow++) {
                dp[numChoose][pow] = temp[numChoose][pow];
            }
        }
    }
    int ans = 0;
    for(int pow=0;pow<=5000;pow++) {
        ans = max(ans,min(pow,dp[k][pow]));
    }
    cout << ans << endl;
}