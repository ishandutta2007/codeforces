#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back



int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int cnt = 0;
        for(int i=1;i<n-1;++i) {
            if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) {
                ++cnt;
            }
        }
        auto calc = [&](int i) {
            int ret = 0;
            if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) ++ret;
            if(i > 1) {
                --i;
                if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) ++ret;
                ++i;
            }
            if(i < n-2) {
                ++i;
                if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) ++ret;
                --i;
            }
            return ret;
        };
        auto chk = [&](int i, int x) {
            assert(i > 0 && i < n-1);
            int pre = calc(i);
            int tmp = a[i];
            a[i] = x;
            int aft = calc(i);
            a[i] = tmp;
            return aft - pre;
        };
        int mn = 0;
        for(int i=1;i<n-1;++i) {
            mn = min(mn, chk(i, a[i-1]));
            mn = min(mn, chk(i, a[i+1]));
        }
        cout << cnt + mn << endl;
    }
}