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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it;
#define WL(t) while(t --)

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,s;
	cin >> n >> s;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll low = 0,high = n,mid,res = 0,cost = 0;
    while (low <= high){
        mid = (low+high)/2;
        vector<ll> b;
        for (int i = 0; i < n; i++){
            b.pb(a[i]+(mid*(i+1)));
        }
        sort(all(b));
        ll ans = 0;
        FOR(i,0,mid){
            ans += b[i];
        }
        if (ans <= s){
            res = mid;
            cost = ans;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << res << " " << cost << endl;
}