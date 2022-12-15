//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;
const int MAXN = LIM;


int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];

        // CHANGE TO t[v] = 0 if using lazy propagation
    }
}

int sum(int v, int tl, int tr, int l, int r) {

//Call this with v=1, tl=0, tr=n-1, l and r of original query

    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {

//ONLY FOR NORMAL, NOT FOR LAZY
//Call this with v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int main(){
	fastio;

	ll n,p;
	cin>>n>>p;
	ll go[n];
	ll ans[n];
	int a[n] = {0};
	build(a,1,0,n-1);

	forn(i,n) cin>>go[i];

	priority_queue<pair<ll,p32> > events;
	priority_queue<int> waiting_indices;

	queue<int> nexttotank;

	bool inuse = 0;

	forn(i,n){
		events.push(mp(-go[i],mp(0,-i)));
	}

	while(!events.empty()){
		pair<ll, p32> t = events.top();
		events.pop();

		t.fi = -t.fi;
		t.se.fi = -t.se.fi;
		t.se.se = -t.se.se;

		// cout<<t.fi<<" "<<t.se<<endl;

		if(t.se.fi == 0){
			if(inuse == 0){
				inuse = 1;
				ans[t.se.se] = t.fi+p;
				update(1,0,n-1,t.se.se,1);
				events.push(mp(-t.fi-p,mp(-1,-t.se.se)));
			}
			else{
				if((t.se.se == 0) || (sum(1,0,n-1,0,t.se.se-1) == 0)){
					// cout<<"ADDED "<<t.se.se<<ln;
					nexttotank.push(t.se.se);
					update(1,0,n-1,t.se.se,1);
				}
				else waiting_indices.push(-t.se.se);
			} 
		}	
		else{
			update(1,0,n-1,t.se.se,0);
			if(waiting_indices.size()!=0){
				int checkind = waiting_indices.top();
				checkind = -checkind;
				if(checkind == 0 || sum(1,0,n-1,0,checkind-1) == 0){
					nexttotank.push(checkind);
					update(1,0,n-1,checkind,1);
					waiting_indices.pop();
				}
			}
			if(nexttotank.size() == 0){
				inuse = 0;
			}
			else{
				int ind = nexttotank.front();
				nexttotank.pop();
				ans[ind] = t.fi+p;
				events.push(mp(-ans[ind],mp(-1,-ind)));
			}
		}

	}

	forn(i, n) cout<<ans[i]<<" ";
	cout<<ln;

	return 0;
}