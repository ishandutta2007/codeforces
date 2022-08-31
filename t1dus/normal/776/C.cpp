#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 10e15
#define mp make_pair

int main() {
	
	ios::sync_with_stdio(false);
	ll n,k;
	cin >> n >> k;
	ll a[n];
	map<ll,ll> mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll s = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++){
	    s += a[i];
	    if (k == 1) ans += mp[s-1];
	    else if (k == -1) ans += mp[s-1]+mp[s+1];
	    else{
	        ll zz = 1;
	        while (abs(zz) < INF){
	            ans += mp[s-zz];
	            zz *= k;
	        }
	    }
	    mp[s] += 1;
	}
	cout << ans << endl;
}