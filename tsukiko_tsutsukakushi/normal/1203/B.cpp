#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
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
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
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
    int q; cin >> q;
    rep(i, q) {
        bool flag = true;
        int n; cin >> n;
        int a[440];
        rep(j, 4 * n) cin >> a[j];
        sort(a, a + 4 * n);
        int m = a[0] * a[4 * n - 1];
        if(a[0] != a[1] || a[4 * n - 2] != a[4 * n - 1]) {
            cout << "NO" << endl; continue;
        }
        for(int j = 2; j <= 2 * n - 1; j += 2) {
            if(a[j] != a[j + 1] || a[4 * n - j - 2] != a[4 * n - j - 1]) {
                cout << "NO" << endl; flag = false; break;
            }
            if(a[j] * a[4 * n - j - 1] != m) {
                cout << "NO" << endl; flag = false; break;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        }
    }
	return 0;
}