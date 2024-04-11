//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long int
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
const int LIM=1e5+5;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
	fastio;

	int n;
	cin>>n;
	vector<pair<p32,int>> sched;
	bool done[n] = {0};
	priority_queue<p32> q;
	int numevents = 0;
	
	forn(i,n){
		int a,b,t;	
		cin>>a>>b>>t;
		sched.pb(mp(mp(a,b),t));
	}

	priority_queue<pair<int,p32> > events;

	forn(i,n){
		events.push(mp(-sched[i].fi.fi,mp(1,i)));
		events.push(mp(-sched[i].fi.se,mp(-1,i)));
		// events.push(mp(min(MOD-sched[i].fi.fi,MOD-sched[i].fi.se+sched[i].se-1),mp(-2,i)));
	}
	
	bool curr = 0;
	int ans = 0;
	int last = 0;
	int tlast = 0;
	int numlast = 0;
	int fintime = 0;
	int jobs = 0;

	while(!events.empty()){
		auto r = events.top();
		numevents++;
		events.pop();
		if(r.se.fi == -1){
			done[r.se.se] = 1;
		}
		if(r.se.fi == 1){
			int i = r.se.se;
			int t = sched[i].se;
			q.push(mp(-t,i));
		}
		int currtime = -r.fi;
		if(r.se.fi == -2){
			if(curr == 1 && numlast == r.se.se){
				if(last+tlast>sched[numlast].fi.se){
					done[numlast] = 1;
				}
			}
			else {
				if(currtime+sched[r.se.se].se > sched[r.se.se].fi.se){
					done[r.se.se] = 1;
				}
			}
		}
		if(curr != 0){
			int num = (currtime-last)/tlast;
			ans += num;
			last = last+num*tlast;
			if(last+tlast>sched[numlast].fi.se){
				done[numlast] = 1;
			}
			if(done[numlast] == 1) {
				last = currtime;
				curr = 0;
			}
		}
		while(!q.empty()){
			auto k = q.top();
			if(currtime-k.fi > sched[k.se].fi.se){
				q.pop();
				continue;
			}
			if(!done[k.se]) break;
			q.pop();
		}

		if(curr == 0){
			if(!q.empty()){
				auto k = q.top();
				tlast = -k.fi;
				numlast = k.se;
				last = currtime;
				curr = 1;
			}
		}
		else{
			auto k = q.top();
			if(-k.fi <= tlast){
				if(-k.fi+currtime <= tlast+last){
					last = currtime;
					numlast = k.se;
					tlast = -k.fi;
				}
				else{
					int fintime = last+tlast;
					events.push(mp(-fintime,mp(0,0)));
				}
			}
		}
		if(curr!=0){
			jobs = (sched[numlast].fi.se-last)/tlast;
			fintime = last+jobs*tlast;
			auto g = events.top();
			if(-g.fi > fintime) events.push(mp(min(-sched[numlast].fi.fi,-fintime),mp(-2,numlast)));
		}
	}
	// cout<<numevents<<" sdfsd"<<ln;

	cout<<ans<<ln;

	return 0;
}