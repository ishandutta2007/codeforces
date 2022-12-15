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

const int LIM=1e5+5, MOD=1e9+7, MAXN = 3e3+5;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;

int n;
p32 t[4*MAXN];

void build(int a[], int v, int tl, int tr){
    if(tl==tr){
        t[v] = mp(a[tl],tl);
    }
    else{
        int tm = (tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

p32 answer(int v, int tl, int tr, int l, int r){
    if(l>r) return mp(0,0);
    if(l==tl && r==tr) return t[v];
    int tm = (tl+tr)/2;
    return max(answer(v*2,tl,tm,l,min(r,tm)),answer(v*2+1,tm+1,tr,max(l,tm+1),r));
}


signed main(){
    fastio;
    
    cin>>n;
    vp32 v;
    int a[n]={0};
    int b[n]={0};
    forn(i,n){
        int x;
        cin>>x;
        v.pb(mp(x,i));
        a[i] = x;
    }

    sort(v.begin(),v.end(),greater<p32>());
    
    forn(i,n){
        if(i==n-1) b[i] = v[n-1].fi;
        else b[i] = v[i].fi-v[i+1].fi;
    }

    int a1 = 0, a2 = 0, a3 = 0;
    int ind1 = 0, ind2 = 0, ind3 = 0;

    build(b,1,0,n-1);

    // forn(i,n) cout<<i<<" "<<b[i]<<ln;

    forn(i,n-1){
        forsn(j,i+1,n-1){
            int cnt1 = i+1, cnt2 = j-i;
            if(2*cnt1<cnt2) continue;
            if(2*cnt2<cnt1) continue;
            if(max(cnt1,cnt2)>2*(n-j-1)) continue;
            p32 ans = answer(1,0,n-1,j+max(1,(max(cnt1,cnt2)+1)/2),j+min(n-j-1,2*min(cnt1,cnt2)));
            // cout<<i<<" "<<j<<" "<<ans.fi<<" "<<ans.se<<ln;
            if(b[i]>=a1){
                if(b[i]>a1){
                    a1 = b[i];
                    a2 = b[j];
                    a3 = ans.fi;
                    ind1 = i;
                    ind2 = j;
                    ind3 = ans.se;
                }
                else{
                    if(b[j]>a2){
                        a1 = b[i];
                        a2 = b[j];
                        a3 = ans.fi;
                        ind1 = i;
                        ind2 = j;
                        ind3 = ans.se;
                    }
                    else if(b[j]==a2){
                        if(ans.fi>a3){
                            a1 = b[i];
                            a2 = b[j];
                            a3 = ans.fi;
                            ind1 = i;
                            ind2 = j;
                            ind3 = ans.se;
                        }
                    }
                }
            }
        }
    }
    // cout<<a3<<ln;
    // cout<<ind1<<" "<<ind2<<" "<<ind3<<ln;
    int fin[n]={0};
    forn(i,n){
        if(i<=ind1) fin[v[i].se] = 1;
        else if(i<=ind2) fin[v[i].se] = 2;
        else if(i<=ind3) fin[v[i].se] = 3; 
        else fin[v[i].se] = -1;
    }
    forn(i,n){
        cout<<fin[i]<<" ";
    }
    cout<<ln;

    return 0;
}