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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int ok = 1;
        for(int i=0;i<n;++i) {
            cin>>b[i];
            b[i]-=a[i];
            if(b[i]<0) ok=0;
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        int l=0;
        while(l<b.size() && !b[l]) ++l;
        if(l == b.size()) {
            cout << "YES\n";
            continue;
        }
        int r=b.size()-1;
        while(!b[r]) --r;
        for(int i=l;i<=r;++i) {
            if(b[i] != b[l]) {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}