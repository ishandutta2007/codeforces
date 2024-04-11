//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
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
const int LIM=4e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int exlink = -1;
    int go[K];
    multiset<int> s;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

struct AhoCorasick{
    vector<Vertex> t = vector<Vertex>(1);

    int add_string(string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        return v;
    }

    int go(int v, char ch);

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    // int go(int v, char ch) {
    //     int c = ch - 'a';
    //     if (t[v].go[c] == -1) {
    //         if (t[v].next[c] != -1)
    //             t[v].go[c] = t[v].next[c];
    //         else
    //             t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    //     }
    //     return t[v].go[c];
    // } 

    int get_exlink(int v){
        if(t[v].exlink == -1){
            int p = get_link(v);
            if(t[p].leaf==1) t[v].exlink = p;
            else{
                if(v == 0 || t[v].p == 0) t[v].exlink = 0;
                else t[v].exlink = get_exlink(p);
            }
        }
        return t[v].exlink;
    }
};

int AhoCorasick::go(int v, char ch){
    int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
}

int val[LIM] = {0};

int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    string s[n];
    int val[n] = {0};
    AhoCorasick a;
    v32 v;
    
    forn(i,n){
        cin >> s[i];
        int add_at = a.add_string(s[i]);
        v.pb(add_at);
        a.t[v[i]].s.insert(0);
    }

    forn(dd,m){
        int type; cin >> type;
        if(type == 1){
            int i, x; 
            cin >> i >> x;
            i--;
            auto it = a.t[v[i]].s.find(val[i]);
            a.t[v[i]].s.erase(it);
            a.t[v[i]].s.insert(x);
            val[i] = x;
        }
        else{
            string g;
            cin >> g;
            int st = 0;
            int ans = -1;
            forn(i,g.length()){
                st = a.go(st, g[i]);
                int cpy = st;
                while(cpy != 0){
                    if(a.t[cpy].leaf){

                        auto it = a.t[cpy].s.end();
                        it--;
                        ans = max(ans, *it);
                    } 
                    cpy = a.get_exlink(cpy);
                }
            }   
            cout << ans << ln;
        }
    }


    return 0;
}