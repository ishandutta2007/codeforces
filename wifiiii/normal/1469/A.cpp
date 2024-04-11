#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
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
        string s;
        cin >> s;
        if(s.size() % 2) {
            cout << "NO\n";
            continue;
        }
        int ok = 1;
        if(s[0] == ')' || s.back() == '(') ok = 0;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}