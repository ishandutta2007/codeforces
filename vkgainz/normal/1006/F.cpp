#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
map<ll, int> dpt[20][20];
map<ll, int> dpd[20][20];
int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    ll a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin >> a[i][j];
    //top
    for(int msk=0;msk<1<<(n-1);msk++) {
        int numR = 0, numD = 0;
        for(int j=0;j<n-1;j++) {
            if(msk&(1<<j)) ++numR;
            else ++numD;
        }
        if(numR<m && numD<n) {
            pair<int, int> curr = {0, 0};
            ll x = 0;
            for(int j=0;j<n-1;j++) {
                x^=a[curr.f][curr.s];
                if(msk&(1<<j)) {
                    ++curr.s;
                }
                else ++curr.f;
            }
            ++dpt[curr.f][curr.s][x];
        }
    }
    for(int msk=0;msk<1<<(m-1);msk++) {
        int numU = 0, numL = 0;
        for(int j=0;j<m-1;j++) {
            if(msk&(1<<j)) ++numL;
            else ++numU;
        }
        if(numL<m && numU<n) {
            pair<int, int> curr = {n-1, m-1};
            ll x = 0;
            for(int j=0;j<m-1;j++) {
                x^=a[curr.f][curr.s];
                if(msk&(1<<j)) {
                    --curr.s;
                }
                else --curr.f;
            }
            ++dpd[curr.f][curr.s][x];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ll target = k^a[i][j];
            for(auto &it : dpt[i][j]) ans+=it.s*1LL*dpd[i][j][target^it.f];
        }
    }
    cout << ans << endl;

}