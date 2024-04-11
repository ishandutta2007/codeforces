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

void z_func(string &s, v32 &z){
    int L=0;
    int R=0;
    int sz = s.size();
    z.assign(sz,0);
    forsn(i,1,sz){
        if(i>R){
            L = R = i;
            while(R<sz && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        }
        else{
            int k = i-L;
            if(z[k]<R-i+1) z[i] = z[k];
            else{
                L = i;
                while(R<sz && s[R-L]==s[R]) R++;
                z[i] = R-L;
                R--;
            }
        }
    }
}

signed main(){
    fastio;
    
    string s;
    cin>>s;
    v32 z;
    z_func(s,z);
    // cout<<z<<ln;
    int max_p = 0;
    v32 pos;
    forn(i,z.size()){
        // cout<<i<<" "<<z[i]<<ln;
        if(i+z[i]!=z.size() && z[i]>0) max_p = max(max_p,z[i]);
        else if(i+z[i]==z.size()) {
            max_p = max(max_p,z[i]-1);
            pos.pb(z[i]);
        }
    }
    // cout<<max_p<<ln;
    // cout<<pos<<ln;
    sort(pos.begin(),pos.end());
    if(pos.size()==0){
        cout<<"Just a legend"<<ln;
        return 0;
    }
    auto it = upper_bound(pos.begin(),pos.end(),max_p);
    if(it == pos.begin()){
        cout<<"Just a legend"<<ln;
    }
    else{
        it--;
        forn(i,*it){
            cout<<s[i];
        }
        cout<<ln;
    }

    return 0;
}