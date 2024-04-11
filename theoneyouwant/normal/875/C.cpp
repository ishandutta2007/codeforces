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

bool change[LIM] = {0};
set<int> adj[LIM];

void dochan(int x){
    forstl(r,adj[x]){
        if(change[r]) continue;
        change[r] = 1;
        dochan(r);
    }
}

signed main(){
    fastio;


    int n,m;
    cin>>n>>m;
    

    v32 v[n];

    forn(i,n){
        int len;
        cin>>len;
        forn(j,len){
            int y;
            cin>>y;
            v[i].pb(y);
        }
    } 

    bool p=1;
    

    forn(i,n-1){
        forn(j,min(v[i+1].size(),v[i].size())){
            if(v[i][j]<v[i+1][j]){
                adj[v[i+1][j]].insert(v[i][j]);
                break;
            } 
            if(v[i][j]>v[i+1][j]){
                change[v[i][j]] = 1;
                break;
            }
        }
    }

    forn(i,m+1){
        if(change[i]==1){
            dochan(i);
        }
    }

    forn(i,n){
        forn(j,v[i].size()){
            if(change[v[i][j]]==1){
                v[i][j] -= (LIM+1);
            }
        }
    }

    forn(i,n-1){
        bool done = 0;
        if(v[i].size()<=v[i+1].size()){
            forn(j,v[i].size()){
                if(v[i][j]<v[i+1][j]) break;
                if(v[i][j]>v[i+1][j]){
                    p=0;
                    break;
                }
            }
        }
        else{
            bool done = 0;
            forn(j,v[i+1].size()){
                if(v[i][j]<v[i+1][j]){
                    done = 1;
                    break;
                } 
                if(v[i][j]>v[i+1][j]){
                    p=0;
                    break;
                }
            }
            if(!done) p=0;
        }
    }

    // cout<<p<<ln;

    if(p) {
        cout<<"Yes"<<ln;
        int k = 0;
        forn(i,m+1){
            if(change[i]) k++;
        }
        cout<<k<<ln;
        if(k!=0){
            forn(i,m+1){
            if(change[i]) cout<<i<<" ";
            }
            cout<<ln;
        }
    }
    else cout<<"No"<<ln;

    return 0;
}