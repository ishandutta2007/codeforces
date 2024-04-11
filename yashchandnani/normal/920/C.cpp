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
	int n;cin>>n;
	int a[n],b[n];char c[n];
	rep(i,n) {
		cin>>a[i];
		b[i] = a[i];
	}
	sort(a,a+n);
	int l = 0,r=0;
	rep(i,n-1){
		cin>>c[i];
		if(c[i]=='1'){
			r++;
		}
		else {
			sort(b+l,b+r+1);
			l=r=i+1;
		}
	}
	sort(b+l,b+r+1);
	bool f = false;
	rep(i,n) if(a[i]!=b[i]) f = true;
	if(f) cout<<"NO";
	else cout<<"YES";
	return 0;
}