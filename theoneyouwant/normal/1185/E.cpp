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
        int n,m;
        cin>>n>>m;
        char inp[n][m];
        char curr[n][m];
        int last = -1;
        int p1 = 0, p2 = 0;
        forn(i,n){
            forn(j,m){
                cin>>inp[i][j];
                if(inp[i][j]!='.'){
                    // last = max(last,inp[i][j]-'a');
                    if(inp[i][j]-'a'>=last){
                        last = inp[i][j]-'a';
                        p1 = i;
                        p2 = j;
                    }
                }
                curr[i][j] = '.';
            }
        }

        bool p =1;
        vector<pair<p32,p32> > colour;
        forn(k,last+1){
            char t = k+'a';
            int l1 = LIM, r1 = LIM, l2 = 0, r2 = 0;
            forn(i,n){
                forn(j,m){
                    if(inp[i][j] == t){
                        if(i<l1 || (i<=l1 && j<r1)){
                            l1 = i;
                            r1 = j;
                        }
                        if(i>l2 || (i>=l2 && j>r2)){
                            l2 = i;
                            r2 = j;
                        }
                    }

                }
            }
            if(l1 == LIM){
                colour.pb(mp(mp(p1,p2),mp(p1,p2)));
                continue;
            }
            if(l1 != l2 && r1 != r2){
                p = 0;
                break;
            }
            colour.pb(mp(mp(l1,r1),mp(l2,r2)));
            forsn(i,l1,l2+1){
                forsn(j,r1,r2+1){
                    curr[i][j] = t;
                }
            }
        }

        if(p){
            forn(i,n){
                forn(j,m){
                    if(inp[i][j] != curr[i][j]) p =0;
                }
            }
        }
        if(p){
            cout<<"YES"<<ln;
            cout<<colour.size()<<ln;
            forstl(r,colour){
                cout<<r.fi.fi+1<<" "<<r.fi.se+1<<" "<<r.se.fi+1<<" "<<r.se.se+1<<ln;
            }
        }
        else cout<<"NO"<<ln;

    }

    return 0;
}