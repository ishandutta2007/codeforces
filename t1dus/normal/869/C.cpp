/*input
6 2 9
*/        
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 998244353
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int mul(int x,int y,int z){
    return (((x*y)%MOD)*z)%MOD;
}

int power(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2);
    if(b%2) return mul(a,x,x);
    else return mul(1,x,x);
}

int fact[5005],ifact[5005];

int C(int n,int k){
    return mul(fact[n],ifact[k],ifact[n-k]);
}

int f(int a,int b){
    int ans = 0;
    REP(k,min(a,b)+1){
        // cout << a << " " << k << " " << C(a,k) << endl;
        // cout << b << " " << k << " " << C(b,k) << endl;
        ans = (ans+mul(C(a,k),C(b,k),fact[k]))%MOD;
    }
    // cout << a << " " << b << " " << ans << endl;
    return ans;
}

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fact[0] = 1;
    ifact[0] = 1;
    FOR(i,1,5005){
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = power(fact[i],MOD-2);
    }
    int a,b,c;
    cin >> a >> b >> c;
    cout << mul(f(a,b),f(b,c),f(c,a));
}