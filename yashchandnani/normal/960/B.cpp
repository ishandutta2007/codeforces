#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[1009],b[1009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,k1,k2;cin>>n>>k1>>k2;
	int k = k1+k2;
	priority_queue<int> q;
	rep(i,n) cin>>a[i];
	rep(i,n) {
		cin>>b[i];
		q.push(abs(b[i]-a[i]));
	}
	rep(i,k){
		int z = q.top();
		q.pop();
		z--;
		z=abs(z);
		q.push(z);
	}
	ll ans = 0;
	while(!q.empty()){
		int z = q.top();
		q.pop();
		ans+=1ll*z*z;
	}
	cout<<ans;

	return 0;
}