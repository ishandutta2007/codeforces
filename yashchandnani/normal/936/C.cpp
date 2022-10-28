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
string s,t;
int n;
vi ans;
void flip(int x){
	reverse(s.begin()+x,s.end());
		ans.pb(n);
		ans.pb(x);
		ans.pb(1);
		s=s.back()+s.substr(0,n-1);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>s>>t;
	rep(i,n){
		repA(j,i,n-1){
			if(s[j] == t[i]){
				flip(j);
				break;
			}
		}
	}
	reverse(s.begin(),s.end());
		ans.pb(n);
	if(s==t&&sz(ans)<=6100){
		cout<<ans.size()<<'\n';
		trav(i,ans) cout<<i<<' ';
	}
	else {
		cout<<-1;
	}
	return 0;
}