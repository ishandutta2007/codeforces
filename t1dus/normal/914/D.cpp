/*input
5
1 2 3 4 5
6
1 1 1 19
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,q,a[500005];

struct node{
	int g;
	unordered_set<int> v;
	int sz;
};

node seg[1005005];

void merge(int i,int l,int r){
	seg[i].g = gcd(seg[l].g,seg[r].g);
	seg[i].sz = seg[l].sz+seg[r].sz;
	seg[i].v.clear();
	if(seg[l].sz == 1){
		seg[i].v.insert(seg[r].g);
	}
	if(seg[r].sz == 1){
		seg[i].v.insert(seg[l].g);
	}
	for(auto x:seg[l].v){
		seg[i].v.insert(gcd(x,seg[r].g));
	}
	for(auto x:seg[r].v){
		seg[i].v.insert(gcd(x,seg[l].g));
	}
}

bool quer(int l,int r,int x){
	if(l == r) return true;
	l += n;
	r += n+1;
	vi lol;
	while(l < r){
		if(l%2) lol.pb(l++);
		if(r%2) lol.pb(--r);
		l /= 2;
		r /= 2;
	}
	seg[2*n] = seg[lol[0]];
	int cur = 2*n+1;
	FOR(i,1,lol.size()){
		merge(cur,cur-1,lol[i]);
		cur ++;
	}
	cur --;
	for(auto y:seg[cur].v){
		if(y%x == 0) return true;
	}
	return false;
}

void upd(int ind,int y){
	ind += n;
	seg[ind].g = y;
	ind /= 2;
	while(ind){
		merge(ind,ind*2,ind*2+1);
		ind /= 2;
	}
}

void solve(){
	cin >> n;
	REP(i,n) cin >> a[i],seg[i+n] = {a[i],{},1};
	for(int i = n-1; i > 0; i--){
		merge(i,2*i,2*i+1);
	}
	cin >> q;
	WL(q){
		int type; cin >> type;
		if(type == 1){
			int l,r,x; cin >> l >> r >> x;
			l --; r --;
			if(quer(l,r,x)) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			int i,y; cin >> i >> y;
			i --;
			upd(i,y);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}