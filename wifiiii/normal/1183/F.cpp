#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;


int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(all(a));
        int ans=a.back();
        int mx=a.back();
        if(mx % 30 == 0) {
            int a1=0,a2=0,a3=0;
            for(int i : a) {
                if(i == mx / 2) a1=1;
                if(i == mx / 3) a2=1;
                if(i == mx / 5) a3=1;
            }
            if(a1&&a2&&a3)ans=max(ans,mx/2+mx/3+mx/5);
        }
        vector<int> v;
        for(int i:a) {
            if(mx%i) {
                v.push_back(i);
            }
        }
        if(v.size()) {
            sort(all(v));
            int ans2 = v.back(), mx2 = v.back();
            for(int i : v) if(mx2 % i) ans2 = max(ans2, mx2 + i);
            ans = max(ans, mx + ans2);
        }
        cout << ans << endl;
        // 30, 15, 10, 9, 1
        // n/2 + n/3 + n/4 = 1/2 + 1/3 + 1/4 = 3/4 + 1/3 = 13/12
        // n/2 + n/3 + n/5 = 5/6 + 1/5 > 1
        //
    }
}