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

int ok[1000006];
int main() {
    int t;
    cin >> t;
    for(int i=0;2020*i<=1000000;++i) {
        for(int j=0;2020*i+2021*j<=1000000;++j) {
            ok[2020*i+2021*j]=1;
        }
    }
    while(t--) {
        int n;
        cin >> n;
        cout << (ok[n] ? "YES" : "NO") << '\n';
    }
}