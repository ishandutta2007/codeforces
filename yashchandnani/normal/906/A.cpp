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
	set<int> s[n];
	string w[n];
	char c[n];
	rep(i,n){
		cin>>c[i]>>w[i];
		rep(j,sz(w[i])){
			s[i].insert(w[i][j]-'a');
		}
	}
	int ans = w[n-1][0]-'a';
	set<int> sns;
	rep(i,26) sns.insert(i);
	bool f = false;
	int fns =0;
	rep(i,n){
		if(f){
			if(c[i]=='!'||(c[i]=='?'&&int(w[i][0]-'a')!=ans)) fns++;
			continue;
		}
		if(c[i]=='!'){
			rep(j,26){
				if(s[i].find(j)==s[i].end()) sns.erase(j);
			}
		}
		else if(c[i]=='.'){
			trav(j,s[i]) sns.erase(j);
		}
		else if(w[i][0]==ans) f = true;
		else {
			int chk = w[i][0]-'a';
			sns.erase(chk);
		}
		if(sz(sns)==1) f = true;
	}

	cout<<fns;

	return 0;
}