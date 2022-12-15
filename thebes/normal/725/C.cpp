#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

string s;
vector<int> pos;
bool marked[30];
char res[2][13];

int main(){
    fastio; cin >> s;
    set<char> bruh;
    char rep = 'a';
    for(int i=0; i<s.size(); i++){
        if(bruh.count(s[i])) marked[i] = true, rep = s[i];
        bruh.insert(s[i]);
    }
    for(int i=0; i<s.size(); i++)
        if(s[i] == rep)
            pos.pb(i);
    int dis = pos[1]-pos[0]-1;
    if(dis == 0){
        cout << "Impossible" << endl;
        return 0;
    }
    if(dis%2){
        dis--;
        dis/=2;
        int p = 12-dis, t = pos[0];
        res[0][p] = s[t++];
        res[1][p] = s[t++];
        for(int i=p+1; i<13; i++) res[1][i] = s[t++];
        for(int i=12; i>p; i--) res[0][i] = s[t++];
        t++;
        vector<pii> v;
        for(int i=p-1; i>=0; i--) v.pb(mp(1,i));
        for(int i=0; i<p; i++) v.pb(mp(0,i));
        reverse(all(v));
        while(t < s.size()){
            res[v.back().first][v.back().second] = s[t++];
            v.pop_back();
        }
        for(int i=0; i<pos[0]; i++){
            res[v.back().first][v.back().second] = s[i];
            v.pop_back();
        }
    }else{
        dis/=2;
        int p = 12-dis, ogp = p, cnt = 0;
        res[0][p++] = rep;
        for(int i=0; i<dis; i++) res[0][p++] = s[pos[0]+(++cnt)];
        for(int i=0; i<dis; i++) res[1][--p] = s[pos[0]+(++cnt)];
        vector<pii> v;
        for(int i=ogp-1; i>=0; i--) v.pb(mp(0,i));
        for(int i=0; i<=ogp; i++) v.pb(mp(1,i));
        reverse(all(v));
        cnt++;
        while(pos[0]+cnt+1 < s.size()){
            res[v.back().first][v.back().second] = s[pos[0]+(++cnt)];
            v.pop_back();
        }
        for(int i=0; i<pos[0]; i++){
            res[v.back().first][v.back().second] = s[i];
            v.pop_back();
        }
    }
    for(int i=0; i<2; i++){
        for(int k=0; k<13; k++)
            cout << res[i][k];
        cout << endl;
    }
}
//ABCDEFGHIJKLMNOPQRSTYUVWXZY