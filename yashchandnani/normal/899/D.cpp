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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll a[10] = {5,50,500,5000,50000,500000,5000000,50000000,500000000,50000000000};	
	int n;cin>>n;
	if(n<5) {cout<<n*(n-1)/2;return 0;}
	int id =0;
	while(n>=a[id+1]) id++;
	int cr = 2*a[id];
	int st = a[id];
	int ml =1;
	ll ans =0;
	while(n>=st){
		ans+=ml*min(cr,n-st+1);
		st+=min(cr,n-st+1);
		ml++;
	}
	while(n>=cr-1) {
		ans--;cr+=2*a[id];
	}
	cout<<ans;
	return 0;
}