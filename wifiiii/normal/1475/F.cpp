#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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

void get(vector<string> &a) {
    int n=a.size();
    for(int i=0;i<n;++i) {
        if(a[0][i] == '1') {
            for(int j=0;j<n;++j) {
                a[j][i]^=1;
            }
        }
    }
    for(int i=0;i<n;++i) {
        if(a[i][0] == '1') {
            for(int j=0;j<n;++j) {
                a[i][j]^=1;
            }
        }
    }
    for(int i=0;i<n;++i) {
        assert(a[0][i] == '0');
        assert(a[i][0] == '0');
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> a(n),b(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        get(a);
        get(b);
        cout << (a == b ? "YES" : "NO") << endl;
    }
}