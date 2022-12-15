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

const int LIM=5e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
const int MAXN = 5e5+5;

int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;

        // CHANGE TO t[v] = 0 if using lazy propagation
    }
}

void rangeupdate(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] = max(t[v],add);
    } else {
        int tm = (tl + tr) / 2;
        rangeupdate(v*2, tl, tm, l, min(r, tm), add);
        rangeupdate(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {

//Get value after lazy propagation USE t[v]=0 VERSION

    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return max(t[v],get(v*2, tl, tm, pos));
    else
        return max(t[v],get(v*2+1, tm+1, tr, pos));
}

const int k = 25;
int st[MAXN][k];

int find(int l, int r){

    if(st[l][0] >= r) return 1;
    if(st[l][k-1] < r) return -1;
    if(st[l][1] >= r) return 2;
    int left = 2, right = k-1;
    int mid = 0;
    while(true){
        mid = (left+right)/2;
        if(st[l][mid] >= r && st[l][mid-1] < r) break;
        if(st[l][mid] >= r) right = mid-1;
        else left = mid+1;
    }
    return (1<<(mid-1)) + find(st[l][mid-1],r);

}

signed main(){
    fastio;
    
    int n,m;
    cin>>n>>m;
    

    forn(i,MAXN){
        forn(j,k){
            st[i][j] = 0;
        }
    }
    // cout<<"OK"<<endl;
    int a[MAXN] = {0};
    build(a,1,0,MAXN-1);

    forn(i,n){
        int l,r;
        cin>>l>>r;
        rangeupdate(1,0,MAXN-1,l,r,r);
    }

    forn(i,MAXN){
        st[i][0] = get(1,0,MAXN-1,i);
        // if(i<5) cout<<i<<" "<<st[i][0]<<ln;
        // if(st[i][0] == i) st[i][0] = i-1;
    }

    forsn(j,1,k){
        for(int i = 0; i< MAXN; i++){
            st[i][j] = max(st[i][j-1],st[st[i][j-1]][j-1]);
        }
    }

    // forn(i,11){
    //     forn(j,4){
    //         cout<<i<<" "<<(1<<j)<<" "<<st[i][j]<<ln;
    //     }
    // }



    forn(i,m){
        int x,y;
        cin>>x>>y;
        // bool p = 0;
        cout<<find(x,y)<<ln;
    }   


    return 0;
}