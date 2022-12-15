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
    
    int n;
    cin>>n;
    ll b[n];
    forn(i,n) cin>>b[i];
    map<int,int> m;
    forn(i,n){
        m[b[i]] = i+1;
    }
    sort(b,b+n);
    map<int,int> diff;
    int ma = 0;
    set<int> act;
    forn(i,n-1){
        diff[b[i+1]-b[i]]++;
        if(diff[b[i+1]-b[i]]>=n-3) act.insert(b[i+1]-b[i]);
    }

    bool done = 0;

    forstl(r,act){
        // cout<<r<<ln;
    int deleteindex = 0;
    int deleteindex2 = 0;
    forn(i,n-1){
        if(b[i+1]-b[i]!=r){
            deleteindex = i+1;
            deleteindex2 = i;
            break;
        }
    }
    // cout<<deleteindex<<" "<<deleteindex2<<ln;

    bool p1 = 1;

    forn(i,n-1){
        if(i == deleteindex) continue;
        if(i+1 == deleteindex){
                if(i+2<=n-1 && b[i+2]-b[i]!=r){
                    p1 = 0;
                    break;
                }
            }
            else{
                if(b[i+1]-b[i]!=r){
                   p1 = 0;
                   break; 
                } 
            }
        }

        if(p1){
            cout<<m[b[deleteindex]]<<ln;
            done = 1;
            return 0;
        }

        p1 = 1;
        forn(i,n-1){
            if(i == deleteindex2) continue;
            if(i+1 == deleteindex2){
                if(i+2<=n-1 && b[i+2]-b[i]!=r){
                    p1 = 0;
                    break;
                }
            }
            else{
                if(b[i+1]-b[i]!=r){
                   p1 = 0;
                   break; 
                } 
            }
        }

        if(p1){
            cout<<m[b[deleteindex2]]<<ln;
            done = 1;
            return 0;
        }
    }
    if(!done) cout<<-1<<ln;
    // cout<<act<<ln;

    return 0;
}