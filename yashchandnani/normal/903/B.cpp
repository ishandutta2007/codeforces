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
	int h,a,c,h2,a2;cin>>h>>a>>c>>h2>>a2;
	vector<int> ans;
	while(h2>0){
			if(h2<=a) {ans.pb(1);h2-=a;}
			else if(h<=a2) {ans.pb(0);h+=c;}
			else {ans.pb(1);h2-=a;}
			h-=a2;
	}
	cout<<sz(ans)<<'\n';
	rep(i,sz(ans)){
		if(ans[i]) cout<<"STRIKE\n";
		else cout<<"HEAL\n";
	}
}