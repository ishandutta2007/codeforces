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
    p32 d[n];
    int dp[26][26];
    int num[26][26];
    int newdp[26][26];

    forn(i,26){
        forn(j,26) {
            dp[i][j] = 0;
            newdp[i][j] = 0;
        }
    }



    forn(i,n){
        string s;
        cin>>s;

        int l = s.length();

        num[s[0]-'a'][s[s.length()-1]-'a']++;
        d[i] = mp(s[0]-'a',s[s.length()-1]-'a');
        int x = s[0]-'a', y = s[s.length()-1]-'a';


        forn(j,26){
            forn(k,26){
                newdp[j][k] = dp[j][k];
            }
        }

        // newdp[x][y] = l;
        newdp[x][y] = max(newdp[x][y],l);
        forn(i,26){
            if(dp[i][x]>0) newdp[i][y] = max(dp[i][y],dp[i][x]+l);
        }
        // forn(j,26){
        //     forn(k,26){
        //         if(dp[j][x] >=1 && dp[y][k] >= 1) newdp[j][k] = max(dp[j][k],dp[j][x]+dp[y][k]+l);
        //     }
        // }
        // forn(j,26){
        //     if(dp[j][x] >=1) newdp[j][y] = max(dp[j][y], dp[j][x]+l);
        // }
        // forn(j,26){
        //     if(dp[x][y] >=1) newdp[x][j] = max(dp[x][j], dp[x][y]+l);
        // }
        forn(j,26){
            forn(k,26){
                dp[j][k] = newdp[j][k];
            }
        }
        // dp = newdp;
        // forn()
    }

    int ans = 0;
    forn(i,26) ans = max(ans,dp[i][i]);
    cout<<ans<<ln;



    return 0;
}