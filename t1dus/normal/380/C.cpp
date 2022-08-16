#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

struct node{
    int l,r,ans;
};

int n,q;
node seg[2000005];
string s;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	n = s.length();
	FOR(i,n,2*n){
	    if(s[i-n] == ')'){
	        seg[i] = {0,1,0};
	    }
	    else{
	        seg[i] = {1,0,0};
	    }
	}
	FORD(i,n-1,1){
	    int t = min(seg[i*2].l,seg[i*2+1].r);
	    seg[i].ans = t+seg[2*i].ans+seg[2*i+1].ans;
	    seg[i].l = seg[2*i].l+seg[2*i+1].l-t;
	    seg[i].r = seg[2*i].r+seg[2*i+1].r-t;
	}
// 	REP(i,2*n) cout << seg[i].l << " " << seg[i].r << " " << seg[i].ans << endl;
	cin >> q;
	while (q --){
	    int x,y;
	    cin >> x >> y;
	    x += n-1;
	    y += n;
	    vi v,v2;
	    while(x < y){
	        if(x%2) v.pb(x++);
	        if(y%2) v2.pb(--y);
	        x /= 2; y /= 2;
	    }
	    REPD(i,v2.size()-1) v.pb(v2[i]);
	    int cur = 0,lf = 0;
	    for(auto i:v){
	        int t = min(lf,seg[i].r);
	        cur += t+seg[i].ans;
	        lf += seg[i].l-t;
	    }
	    cout << cur*2 << endl;
	}
}