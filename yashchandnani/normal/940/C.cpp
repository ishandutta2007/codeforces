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
	int n,k;cin>>n>>k;
	set<char> t;
	string s;cin>>s;
	trav(i,s) t.insert(i);
	if(k>n){
		trav(i,s) cout<<i;
		rep(i,k-n) cout<<*(t.begin());
	}
	if(k<n){
		n = k;
	}
	if(k==n){
		repD(i,n-1,0){
			if(t.upper_bound(s[i])!=t.end()){
				s[i] = *(t.upper_bound(s[i]));
				repA(j,i+1,n-1) s[j] = *(t.begin());
				break;
			}
		}
		cout<<s.substr(0,n);
	}
	return 0;
}