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
    
    ll n, m;
    cin>>n>>m;

    ll valid = 0;
    string flag[n];
    forn(i,n) cin>>flag[i];

    ll precomp[n+1][m+1];
    bool done[n+1][m+1];
    forn(i,n+1){
        forn(j,m+1){
            precomp[i][j] = 0;
            done[i][j] = 0;
        }
    }

    forn(i,n){
        string s = flag[i];
        forn(j,s.length()){
            if(j>0 && s[j] == s[j-1]){
                precomp[i][j] = precomp[i][j-1]-1;
            }
            else{
                int k = 1, t = j+1;
                while(t<m && s[t] == s[j]){
                    t++;
                    k++;
                }
                precomp[i][j] = k;
            }
        }
    }

        for(int i = 1; i < n-1; i += 1){
            forn(j,m){
                if(done[i][j]) continue;
                done[i][j] = 1;
                int tup = i, tdown = i;
                ll l1 = 1e9, l2 = 1e9, l3 = 1e9;
                l2 = precomp[i][j];
                while(true){
                    if(tup == 0) break;
                    if(tup > 0 && flag[tup-1][j] == flag[i][j]) tup--;
                    else break;
                    l2 = min(l2, precomp[tup][j]);
                    done[tup][j] = 1;
                }
                while(true){
                    if(tdown == n-1) break;
                    if(tdown < n-1 && flag[tdown+1][j] == flag[i][j]) tdown++;
                    else break;
                    l2 = min(l2, precomp[tdown][j]);
                    done[tdown][j] = 1;
                }
                int length = tdown-tup+1;
                int startup = tup-1;
                int startdown = tdown+1;
                if(startup-length+1<0) continue;
                if(startdown+length-1>n-1) continue;
                rforsn(y,startup,startup-length+1){
                    l1 = min(l1, precomp[y][j]);
                    if(flag[y][j] != flag[startup][j]) l1 = 0;
                }
                forsn(y,startdown,startdown+length){
                    l3 = min(l3, precomp[y][j]);
                    if(flag[y][j] != flag[startdown][j]) l3 = 0;
                }
                valid += min({l1,l2,l3});
            }
        // cout<<l<<" "<<valid<<ln;
    }
    
    cout<<valid<<ln;


    return 0;
}