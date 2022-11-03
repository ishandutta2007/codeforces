/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> Zalgo(const string& s) {
    int n = (int)s.size();
    vector<int> res(n);
    res[0] = n;
    int i = 1, j = 0;
    while(i < n) {
        while(i + j < n && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0) {++i; continue;}
        int k = 1;
        while(i + k < n && k + res[k] < j) res[i + k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

string find_palindrome(string s) {
	string t = s;
	reverse(all(t));
	string u = s + "_" + t;
	auto zu = Zalgo(u);
	int n = (int)s.size();
	for(int i = n + 1; i < 2 * n + 1; ++ i) {
		//cerr << zu[i] << endl;
		if(zu[i] == 2 * n + 1 - i) {
			return s.substr(0, 2 * n + 1 - i);
		}
	}
	return "";
}

void solve() {
	string s; cin >> s;
	int n = (int)s.size();
	int j = 0;
	for(int i = 0; i < n / 2; ++ i) {
		if(s[i] == s[n - 1 - i]) {
			j ++;
		} else {
			break;
		}
	}
	string left = s.substr(0, j);
	string right = left;
	reverse(all(right));
	s = s.substr(j, n - 2 * j);
	n -= 2 * j;
	//cerr << left << endl;
	if(n == 0) {
		cout << left << right << endl;
		return;
	}
	string t = s;
	reverse(all(t));
	string res = find_palindrome(s), res2 = find_palindrome(t);
	//cerr << res << endl;
	if(res.size() < res2.size()) {
		cout << left << res2 << right << endl;
	} else {
		cout << left << res << right << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}