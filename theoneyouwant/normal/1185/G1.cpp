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

ll dp[16][16][16][3];

ll solve(int last, int n1, int n2, int n3){
    if(n1<0 || n2<0 || n3<0) return 0;
    if(n1 == 0 && n2 == 0 && n3 == 0) return 1;
    if(dp[n1][n2][n3][last-1]!=-1) return dp[n1][n2][n3][last-1];
    ll ans = 0;
    if(last == 1){
        ans = solve(2,n1,n2-1,n3)+solve(3,n1,n2,n3-1);
    }
    else if(last == 2){
        ans = solve(3,n1,n2,n3-1)+solve(1,n1-1,n2,n3);
    }
    else{
        ans = solve(2,n1,n2-1,n3)+solve(1,n1-1,n2,n3);
    }
    ans %= MOD;
    dp[n1][n2][n3][last-1] = ans;
    return dp[n1][n2][n3][last-1];
}

// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    ll n,t;
    cin>>n>>t;
    ll length[n], genre[n];
    forn(i,n){
        cin>>length[i]>>genre[i];
    }
    ll total = 0;
    ll fact[16] = {0};
    fact[0] = 1;
    fact[1] = 1;
    forsn(i,2,16){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }

    // forn(i,16) forn(j,16) forn(k,16) forn(l,3) dp[i][j][k][l] = -1;

    forn(i,16){
        forn(j,16){
            forn(k,16){
                forn(l,3){
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }

    forn(i,16){
        forn(j,16){
            forn(k,16){
                forn(l,3){
                    solve(l+1,i,j,k);
                }
            }
        }
    }

    forn(i,1LL<<n){
        v64 v;
        int x = i;
        forn(j,n){
            v.pb(x%2);
            x = x/2;
        }
        ll tot = 0;
        forn(j,n){
            if(v[j]==1) tot += length[j];
        }
        if(tot != t) continue;
        // cout<<"OK"<<endl;
        ll n1 = 0, n2 = 0, n3 = 0;
        forn(j,n){
            if(v[j]==1){    
                if(genre[j]==1) n1++;
                else if(genre[j]==2) n2++;
                else if(genre[j]==3) n3++;
            }
        }
        // ll ans = 0;
        // ans += dp[n1-1][n2][n3][0]+dp[n1][n2-1][n3][1]+dp[n1][n2][n3-1][2];
        // ans %= MOD;
        ll ans = solve(1,n1-1,n2,n3)+solve(2,n1,n2-1,n3)+solve(3,n1,n2,n3-1);
        ans %= MOD;
        ans *= fact[n1];
        ans %= MOD;
        ans *= fact[n2];
        ans %= MOD;
        ans *= fact[n3];
        ans %= MOD;
        total += ans;
        total %= MOD;
    }
    cout<<total<<ln;

    return 0;
}