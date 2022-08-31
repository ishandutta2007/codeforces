#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
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

int n;
int a[1000005],b[1000005];
ll seg[2000005];
mii M;
ll ans = 0,cur,cur2;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n){
	    cin >> a[i];
	    b[i] = a[i];
	}
	sort(b,b+n);
	REP(i,n){
	    M[b[i]] = i;
	}
	REP(i,2*n) seg[i] = 0;
	REP(i,n){
	    a[i] = M[a[i]];
	}
	int p = a[0]+n;   
    while(p > 0){
        seg[p] ++;
        p /= 2;
    }
	FOR(i,1,n-1){
        int l = a[i]+1+n,r = 2*n;
        cur = 0;
        cur2 = 0;
        while(l < r){
            if(l%2) cur += seg[l++];
            if(r%2) cur += seg[--r];
            l /= 2;
            r /= 2;
        }
        p = a[i]+n;   
        while(p > 0){
            seg[p] ++;
            p /= 2;
        }
        // number of powers > a[x] in the left = cur
        // number of powers < a[x] in the left = x-cur
        // number of powers < a[x] = a[x]
        // number of powers < a[x] in the right = a[x]-x+cur
        ans += cur*(a[i]-i+cur);
	}
	cout << ans << endl;
}