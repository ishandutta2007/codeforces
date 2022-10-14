#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forn(i, n) for(int i = 0; i<(n);i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;	

#define vi vector<int>
#define FOR(i, a) for(int i = 0; i < a; i++)
#define pb push_back
#define ld double
#define mp make_pair
#define f first
#define s second
#define EACH(x, y) for(auto &x : y)
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef long double lld;

ll n, m, k;
string s;
int t, g, i;
const ll INF = 1e9;
vector<int> arr(5000);
namespace number_theory {
    const int mod =(int) 1e9+7;
    int gcd(int x, int y) {
        return __gcd(x, y);
    }
    ll gcd(ll x, ll y) {
        return __gcd(x, y);
    }
    vector<int> sieve(int x){
        assert(x<100000&&x>1);
        bool a[100000];
        vector<int> s;
        memset(a, 1, sizeof(a));
        // N times, primes occur n / log n times, from 1 to n, which means the efficiency is n log (log n)
        for(int i = 2; i<= x; i++){
            if(a[i]) {
                for(int p = i*i; p<=x; p+=i) {
                    a[p]=0;
                }
            }
        }
        
        for(int i = 2; i<=x; i++){
            if(a[i]) s.push_back(i);
        }
        return s;
    }
    vector<int> factors(int x) {
        set<int> fac;
        vector<int> space;
        for(int i = 1; i<= int(sqrt(x)); i++) {
            if(x%i==0) {
                fac.insert(x/i);
                fac.insert(i);
            }
        }
        
        for(auto &y : fac) {
            space.push_back(y);
        }
        return space;
    }
    int lcm(int x, int y) {
        int ans = x*y/__gcd(x, y);
        return ans;
    }
    bool prime(int x) {
        for(int i = 2; i<=int(sqrt(x)); i++) {
            if(x%i==0) return false;
        }
        return true;
    }
    vector<pair<int, int>> prime_factors(int x) {
        assert(x<10000);
        vector<int> a = sieve(x);
        vector<int> b(10000);
        int n = x;
        for(auto &i : a) {
            while(n%i==0){ 
                n/=i;
                b[i]++;
            }
        }
        vector<pair<int, int>> result;
        for(int i =0; i < 10000; i++) {
            if(b[i]>0) {
                result.push_back(make_pair(i, b[i]));
            }
        }
        return result;
    }
}
void solve() {
	int e, b, c, d;
    cin >> e >> b>> c >> d;
    int a[4] =  {e,b,c,d};
    cin  >>s;
    ll cnt =0;
    for(int i =0; i < s.size(); i++) {
        cnt+=a[s[i]-'0'-1];
    }
    cout << cnt;
}

void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
	
int main() {
	fast_io();

	
    solve();
		
}