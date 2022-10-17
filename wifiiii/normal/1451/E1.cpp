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

int x[1<<16|5], ans[1<<16|5];
int main() {
    int n;
    cin >> n;
    int lg = 31 - __builtin_clz(n);
    for(int i=2;i<=n;++i) {
        cout << "XOR " << 1 << " " << i << endl;
        cin >> x[i];
    }
    int and12, and13, and23;
    cout << "AND " << 1 << " " << 2 << endl;
    cout << "AND " << 1 << " " << 3 << endl;
    cout << "AND " << 2 << " " << 3 << endl;
    cin >> and12 >> and13 >> and23;
    int p12 = 2 * and12 + x[2], p13 = 2 * and13 + x[3], p23 = 2 * and23 + (x[2] ^ x[3]);
    int m23 = p12 - p13;
    ans[2] = (p23 + m23) / 2;
    ans[1] = ans[2] ^ x[2];
    for(int i=3;i<=n;++i) ans[i] = x[i] ^ ans[1];
    cout << "! ";
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}