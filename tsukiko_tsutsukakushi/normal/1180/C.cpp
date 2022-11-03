#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll n, q; cin >> n >> q;
    ll a[100100];
    rep(i, n) cin >> a[i];
    ll b[100100];
    b[0] = a[0];
    ll c[100100];
    rep1(i, n - 1) {
        b[i] = max(b[i - 1], a[i]);
        c[i - 1] = min(b[i - 1], a[i]);
    }

    rep(i, q) {
        ll m; cin >> m;
        m --;
        if(m < n - 1) {
            cout << b[m] << " " << a[m + 1] << endl;
        } else {
            ll k = (m - n + 1) % (n - 1);
            cout << b[n - 1] << " " << c[k] << endl;
        }
    }
	return 0;
}