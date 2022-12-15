//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

v32 adj[LIM];
int root[LIM];
int degree[LIM];
tuple<int,int,int> t[LIM];

int main(){
	fastio;

	int n; cin>>n;
    bool marked[6*n] = {0};

    forn(i,3*n){
        int x; cin>>x;
        x--; marked[x] = 1;
    }

    stack<pair<pair<bool,int>,v32>> s;

    int cnt = 0;

    forn(i,6*n){
        if(!s.empty() && marked[i] == s.top().fi.fi){
            auto v = s.top();
            s.pop();
            v.se.pb(i);
            if(v.se.size() == 3){
                t[v.fi.se] = {v.se[0], v.se[1], v.se[2]};
                // cout<<"stack "<<v.se[0]+1<<" "<<v.se[1]+1<<" "<<v.se[2]+1<<ln;
                if(s.empty()){
                    root[v.fi.se] = 1;
                }
                else{
                    adj[v.fi.se].pb(s.top().fi.se);
                    // adj[s.top().fi.se].pb(v.fi.se);
                    degree[s.top().fi.se]++;
                    degree[v.fi.se]++;
                }
            }
            else{
                s.push(v);
            }
        }
        else{
            v32 vv;
            vv.pb(i);
            s.push(mp(mp(marked[i], cnt), vv));
            cnt++;
        }
    }

    // forn(i,2*n){
    //     cout<<i<<" "<<get<0>(t[i])+1<<" "<<get<1>(t[i])+1<<" "<<get<2>(t[i])+1<<ln;
    // }

    int deleted[cnt] = {0};
    priority_queue<p32> q0, q1;

    forn(i,cnt){
        if(marked[get<0>(t[i])] == 1 && degree[i] <= 1 && (root[i] == 0 || degree[i] == 0)){
            q0.push(mp(-root[i], i));
            deleted[i] = 1;
        }
        else if(degree[i] <= 1 && (root[i] == 0 || degree[i] == 0)){
            q1.push(mp(-root[i], i));
            deleted[i] = 1;
        }
    }

    forn(i,n){
        auto ans = q0.top();
        q0.pop();
        int a1, a2, a3;
        tie(a1, a2, a3) = t[ans.se];
        cout<<a1+1<<" "<<a2+1<<" "<<a3+1<<ln;
        forstl(r,adj[ans.se]){
            if(deleted[r]) continue;
            degree[r]--;
            if((degree[r] == 1 && root[r] == 0) || degree[r] == 0){
                deleted[r] = 1;
                q1.push(mp(-root[r], r));
            }
        }
        ans = q1.top();
        q1.pop();
        tie(a1, a2, a3) = t[ans.se];
        cout<<a1+1<<" "<<a2+1<<" "<<a3+1<<ln;
        forstl(r,adj[ans.se]){
            if(deleted[r]) continue;
            degree[r]--;
            if((degree[r] == 1 && root[r] == 0) || degree[r] == 0){
                deleted[r] = 1;
                q0.push(mp(-root[r], r));
            }
        }

    }


	return 0;
}