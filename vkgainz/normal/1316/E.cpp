#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
ll dp[100001][1<<7];
vector<int> s[100001];
int a[100001];
int n,p,k;
bool cmp(const int &i, const int &j) {
    return i>j;
}
bool cmp2(vector<int> &x, vector<int> &y) {
    return x[p]>y[p];
}
int main() {
    cin >> n >> p >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        s[i] = vector<int>(p+1);
        for(int j=0;j<p;j++) cin >> s[i][j];
        s[i][p] = a[i];
    }
    //sort decreasing by a[i]
    sort(s,s+n,cmp2);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) {
        for(int msk=0;msk<1<<p;msk++) {
            int cnt = 0;
            for(int j=0;j<p;j++) {
                if(msk&(1<<j)) {
                    ++cnt;
                }
            }
            if(cnt>i+1) { //check this
                continue;
            }
            for(int j=0;j<p;j++) {
                if(msk&(1<<j)) {
                    //simulate take
                    if(i>0) dp[i][msk] = max(dp[i][msk],dp[i-1][msk^(1<<j)]+s[i][j]);
                    else dp[i][msk] = max(dp[i][msk],s[i][j]*1LL);
                }
            }
            //don't take
            if(i+1-cnt<=k && cnt<=i) {
                if(i>0) dp[i][msk] = max(dp[i][msk],dp[i-1][msk]+a[i]);
                else dp[i][msk] = max(dp[i][msk],a[i]*1LL); //check this
            }
            if(i>0) dp[i][msk] = max(dp[i][msk],dp[i-1][msk]);
        }
    }
    cout << dp[n-1][(1<<p)-1];

}