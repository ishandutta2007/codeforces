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
	int n,ans=0;cin>>n;
	string s;cin>>s;
	int p = (s[0]=='U')?1:0;
	int x=0,y=0;
	rep(i,n){
		int n;
		if(s[i]=='U') y++;
		else x++;
		if(x>y) n = 0;
		else if(y>x) n=1;
		else n=p;
		if(n!=p) ans++;
		p=n;
	}
		
	cout<<ans;
	return 0;
}