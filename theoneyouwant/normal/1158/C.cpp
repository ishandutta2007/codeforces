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
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
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

const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    int tests;
    cin>>tests;
    
    while(tests--){
        int n;
        cin>>n;
        v32 adj[n+1];
        // vp32 v;
        int next[n+1] = {0};
        int ognext[n+1] = {0};

        forsn(i,1,n+1){
            int x;
            cin>>x;
            next[i] = x;
            // if(x!=n+1) v.pb(mp(x,n-i));
            if(x!=n+1 && x!=-1) adj[x].pb(i);
        }
        forn(i,n+1) ognext[i]  = next[i];

        priority_queue<int> q;

        forsn(i,1,n+1){
            while(!q.empty() && n-q.top()==i) q.pop();
            if(next[i]==-1){
                // int k;
                if(!q.empty()) {
                    next[i] = n-q.top();
                    adj[n-q.top()].pb(i);
                }
                else next[i] = n+1;
            }
            if(next[i]!=n+1) q.push((n-next[i]));
        }
        
        int asn = n;
        int ans[n+1] = {0};
        int visited[n+1] = {0};
        forsn(i,1,n+1){
            if(next[i] == n+1){
                // cout<<i<<ln;
                priority_queue<int> q;
                q.push(n-i);
                while(!q.empty()){
                    int t = n-q.top();
                    q.pop();
                    visited[t] = 1;
                    ans[t] = asn;
                    asn--;
                    forstl(r,adj[t]){
                        if(visited[r]) continue;
                        q.push(n-r);
                    }
                }
            }
        }
        rforsn(i,n,1){
            if(ans[i]==0){
                ans[i] = asn;
                asn--;
            }
        }
        // forsn(i,1,n+1) cout<<i<<" "<<ans[i]<<ln;
        bool p=1;
        stack<p32> s;
        rforsn(i,n,1){
            while(s.size()>0 && s.top().fi<ans[i]) s.pop();
            if(s.size()==0){
                if(ognext[i] == n+1 || ognext[i] == -1);
                else p=0;
            }
            else{
                if(ognext[i] == s.top().se || ognext[i] == -1) ;
                else p=0;
            }
            // cout<<i<<" "<<p<<ln;
            s.push(mp(ans[i],i));
        }

        if(p){
            forsn(i,1,n+1) cout<<ans[i]<<" ";
            cout<<ln;
        }
        else cout<<-1<<ln;
    }

    return 0;
}