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
typedef vector<pii> vii;
int inf = 1e9+7;
bool t;
typedef vector<vector<pii> > vvi;
vvi ans;
vi op;
int mn(int a,int b){
	if(t==1) return a-b;
	else return a+b;
}
int mx(int a,int b){
	if(t==0) return a-b;
	else return a+b;
}
void solve(){
	vii a = ans.back();
	ans.pop_back();
	vii b = ans.back();
	ans.pop_back();
	vii c(101,mp(-inf,inf));
	rep(i,101){
		rep(j,101){
			if(i+j>100||b[i].fst==-inf||a[j].fst==-inf) continue;
			c[i+j].snd = min(c[i+j].snd,mx(b[i].snd,a[j].fst));
			if(i+j<100) c[i+j+1].snd = min(c[i+j+1].snd,mn(b[i].snd,a[j].fst));
			c[i+j].fst = max(c[i+j].fst,mx(b[i].snd,a[j].fst));
			if(i+j<100) c[i+j+1].fst = max(c[i+j+1].fst,mn(b[i].snd,a[j].fst));
			c[i+j].snd = min(c[i+j].snd,mx(b[i].fst,a[j].snd));
			if(i+j<100) c[i+j+1].snd = min(c[i+j+1].snd,mn(b[i].fst,a[j].snd));
			c[i+j].fst = max(c[i+j].fst,mx(b[i].fst,a[j].snd));
			if(i+j<100) c[i+j+1].fst = max(c[i+j+1].fst,mn(b[i].fst,a[j].snd));
			c[i+j].snd = min(c[i+j].snd,mx(b[i].snd,a[j].snd));
			if(i+j<100) c[i+j+1].snd = min(c[i+j+1].snd,mn(b[i].snd,a[j].snd));
			c[i+j].fst = max(c[i+j].fst,mx(b[i].snd,a[j].snd));
			if(i+j<100) c[i+j+1].fst = max(c[i+j+1].fst,mn(b[i].snd,a[j].snd));
			c[i+j].snd = min(c[i+j].snd,mx(b[i].fst,a[j].fst));
			if(i+j<100) c[i+j+1].snd = min(c[i+j+1].snd,mn(b[i].fst,a[j].fst));
			c[i+j].fst = max(c[i+j].fst,mx(b[i].fst,a[j].fst));
			if(i+j<100) c[i+j+1].fst = max(c[i+j+1].fst,mn(b[i].fst,a[j].fst));
		}
	}
	ans.pb(c);
	op.pop_back();
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;cin>>s;
	int p,m;cin>>p>>m;
	t=(p>m);
	trav(i,s){
		if(i=='(') op.pb(0);
		else if(i=='?') {
			op.pb(1);
		}
		else if(i==')'){ 
			solve();
			op.pop_back();
		}
		else{
			int v = i-'0';
			vii temp(101,mp(-inf,inf));
			temp[0] = mp(v,v);
			ans.pb(temp);
		}
	}
	cout<<ans[0][min(p,m)].fst;
	return 0;
}