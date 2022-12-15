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
        string s;
        cin>>s;
        vector<char> v1,v2,vans,vok;
        forn(i,s.length()) vok.pb(s[i]);
        sort(vok.begin(),vok.end());
        forn(i,s.length()){
            if((vok[i]-'a')%2==1) v2.pb(vok[i]);
            else v1.pb(vok[i]);
        }
        sort(v1.begin(),v1.end(),greater<char>());
        sort(v2.begin(),v2.end(),greater<char>());
        int pt1=0,pt2=0;
        forstl(r,v1) vans.pb(r);
        forstl(r,v2) vans.pb(r);
        bool p=1;
        // forstl(r,vans) cout<<r;
        // cout<<ln;
        forsn(i,1,s.length()){
            if(abs(vans[i]-vans[i-1])==1) p=0;
        }
        if(p){
            forstl(r,vans) cout<<r;
            cout<<ln;
        }

        else{
            p=1;
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            vans.clear();
            forstl(r,v1) vans.pb(r);
            forstl(r,v2) vans.pb(r);
            bool p=1;
            forsn(i,1,s.length()){
                if(abs(vans[i]-vans[i-1])==1) p=0;
            }
            // forstl(r,vans) cout<<r;
            // cout<<ln;
            if(p){
                forstl(r,vans) cout<<r;
                cout<<ln;
            }
            else cout<<"No answer"<<ln;
        }
    }

    return 0;
}