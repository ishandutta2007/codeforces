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

const int LIM=3e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;


int link[LIM] = {0};
int size[LIM] = {0};
int lsize[LIM] = {0};
int rsize[LIM] = {0};
int rside[LIM] = {0};
int lside[LIM] = {0};

int find(int x){
    int a = x;
    while(x!=link[x]){
        x = link[x];
    }
    link[a] = x;
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a]<size[b]) swap(a,b);
    size[a]+=size[b];
    link[b] = a;
    if(a<b){
        rsize[rside[b]] += rsize[rside[a]];
        rside[a] = rside[b];
        lsize[lside[a]] += lsize[lside[b]];
        lside[a] = lside[a];
    }
    else{
        rsize[rside[a]] += rsize[rside[b]];
        rside[a] = rside[a];
        lsize[lside[b]] += lsize[lside[a]];
        lside[a] = lside[b];
    }
}



signed main(){
    fastio;
    
    int n;
    cin>>n;
    forn(i,LIM) link[i] = i;
    forn(i,LIM) size[i] = 1;
    forn(i,LIM) rside[i] = i;
    forn(i,LIM) lsize[i] = 1;
    forn(i,LIM) rsize[i] = 1;
    forn(i,LIM) lside[i] = i;

    bool set[n] = {0};
    int bsize[n] = {0};
    int fsize[n] = {0};   

    cout<<1<<" ";
    int lastans[n+1] = {0};
    forn(i,n){
        int x;
        int ans = {0};
        cin>>x;
        x--; 
        set[x] = 1;
        // if(x==4){
        //     cout<<ln;
        //     forn(j,8){
        //         cout<<j<<" ";
        //         int t = j;
        //         while(t!=link[t]) t = link[t];
        //         cout<<t<<ln;
        //     }
        // }
        // if(i==0){
        //     lastans[i] = 1;
        //     continue;
        // }
        int change=0;
        int y = x-1;
        if(y>=0){
            while(y!=link[y]) y = link[y];
        }
        int z = x+1;
        if(z>=0){
            while(z!=link[z]) z = link[z];
        }

        if(x>0 && set[x-1]==1){
            
            if(x<n-1 && set[x+1]==1){
                // int z = x+1;
                if(rside[z]==n-1){
                    // if(x==4) cout<<"OK"<<ln;
                    // if(x==4) cout<<y<<ln;
                    // if(x==4) cout<<y<<ln;
                    // if(x==5) cout<<"HERE "<<y<<" "<<rside[y]<<" "<<rsize[rside[y]]<<ln;
                    change -= rsize[rside[y]];
                }
                else{
                    change += 1;
                }
            }
            else if(x<n-1 && set[x+1]==0){
                change += 1;
            }
            else if(x==n-1){
                change -= rsize[rside[y]];
            }
        }
        else if(x>0 && set[x-1]==0){
            if(x<n-1 && set[x+1]==1){
                if(rside[z]==n-1){
                    change += 0;
                }
                else{
                    change += 1;
                }
            }
            else if(x<n-1 && set[x+1]==0){
                change += 1;
            }
            else if(x==n-1){
                change += 0;
                // change -= rsize[rside[x-1]];
            }
        }
        else if(x==0){
            if(x<n-1 && set[x+1]==1){
                if(rside[z]<n-1){
                    change += 1;
                }
                else{
                    change += 0;
                }
            }
            else if(x<n-1 && set[x+1]==0){
                change += 1;
            }
            else if(x==n-1){
                change = 0;
            }
        }
        if(x>0 && set[x-1]==1){
            unite(x-1,x);
        }
        if(x<n-1 && set[x+1]==1){
            unite(x+1,x);
        }
        if(i==0) lastans[i] = 1+change;
        else lastans[i] = lastans[i-1] + change;
        cout<<lastans[i]<<" ";
    }
    cout<<ln;

    return 0;
}