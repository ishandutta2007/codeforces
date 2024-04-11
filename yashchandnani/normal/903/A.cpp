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
	bool ans[101]= {false};
	ans[0] = true;
	repA(i,3,100){
		if(ans[i-3]) ans[i]=true;
		else if(i>=7&&ans[i-7]) ans[i] =true;
	}
	rep(i,n){
		int x;cin>>x;
		if(ans[x]) cout<<"YES\n";
		else cout<<"NO\n";
	}


}