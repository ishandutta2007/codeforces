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
//#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[1005],mn[1005];
int main() {
    int t;
    cin>>t;
    a[0] = 1e9;
    while(t--) {
        int n;
        cin>>n;
        ii cin>>a[i];
        mn[n+1] = 0;
        for(int i=n;i>=1;--i) {
            if(a[i] < a[mn[i+1]]) {
                mn[i] = i;
            } else mn[i] = mn[i+1];
        }
        int ok = 0, x, y, z;
        for(int i=1;i<=n;++i) {
            if(ok) break;
            for(int j=i+1;j<n;++j) {
                if(a[j] > a[i] && a[j] > a[mn[j+1]]) {
                    ok = 1;
                    x = i, y = j, z = mn[j+1];
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES" << endl;
            cout << x << " " << y << " " << z << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}