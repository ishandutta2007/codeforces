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
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(), a.end(), greater<int>());
        ll alice = 0, bob = 0;
        for(int i=0;i<n;++i) {
            if(i&1) {
                if(a[i] % 2 == 1) bob += a[i];
            } else {
                if(a[i] % 2 == 0) alice += a[i];
            }
        }
        if(alice > bob) cout << "Alice\n";
        else if(alice < bob) cout << "Bob\n";
        else cout << "Tie\n";
    }
}