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
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), ans(n);
        for(int i=0;i<n;++i) {
            cin>>a[i]>>b[i];
            if(a[i]>b[i]) swap(a[i],b[i]);
        }
        vector<int> ord(n);
        iota(al(ord), 0);
        sort(al(ord), [&](int i,int j){return a[i]<a[j];});
        int min_b = INT_MAX, minpos = -1;
        int j = 0;
        for(int i=0;i<n;++i) {
            while(a[ord[j]] < a[ord[i]]) {
                if(b[ord[j]] < min_b) {
                    min_b = b[ord[j]];
                    minpos = ord[j];
                }
                ++j;
            }
            if(b[ord[i]] > min_b) {
                ans[ord[i]] = minpos + 1;
            } else {
                ans[ord[i]] = -1;
            }
        }
        for(int i=0;i<n;++i) cout<<ans[i]<<" ";
        cout<<endl;
    }
}