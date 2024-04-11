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

int chk(string &s, string &t) {
    if(t.size() > s.size()) return 0;
    if(s.size() % t.size()) return 0;
    for(int i=0;i<s.size();i+=t.size()) {
        if(s.substr(i,t.size()) != t) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        string aa = a;
        int ok = 0;
        for(int i=1;i<=25;++i) {
            if(chk(a, b)) {
                cout << a << endl;
                ok = 1;
                break;
            }
            a += aa;
        }
        if(!ok) cout << -1 << endl;
    }
}