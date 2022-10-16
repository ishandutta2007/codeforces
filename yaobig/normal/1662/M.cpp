#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
#include <complex>
#include <cassert>
#include <queue>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define deb(a) cerr<< #a << "= " << (a)<<"\n";
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef complex<double> base;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "[ "; for (int i=0; i<(int)v.size(); i++) stream << v[i] << " "; stream << "]"; return stream; }
template<class T> ostream& operator<<(ostream& stream, const pii p){ stream << "(" << p.fi << "," << p.se << ")"; return stream; }
 
ll fpow(ll x, ll p, ll m){ll r=1; for (;p;p>>=1){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
ll inv(ll a, ll b){ return a<2 ? a : ((a-inv(b%a,a))*b+1)/a%b; }
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}
 

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
        int N,M;
        cin >> N >> M;

        int i, mr=0, mw=0;
        for (i=1; i<=M; i++){
            int r,w;
            cin >> r >> w;
            mr=max(mr, r);
            mw=max(mw, w);
        }

        if (mr+mw>N) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        string s;
        for (i=1; i<=mr; i++)
            s+='R';

        for (i=1; i<=mw; i++)
            s+='W';

        int rem=N-(mr+mw);
        for (i=1; i<=rem; i++)
            s+='R';

        cout << s << "\n";

    }
	return 0;
}