// how to come up with such solution :(

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(1234);

int n;
string s,t;
map<pair<string,int>,vi> mp;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep1(i,n){
        cin>>s>>t;
        int mask=0;
        for (auto c:t){
            mask|=(1<<(c-'a'));
        }
        while (sz(s)){
            auto c=s.back();
            int pos=c-'a';
            if (mask>>pos&1) s.pop_back();
            else break;
        }
        mp[{s,mask}].pb(i);
    }
    cout<<sz(mp)<<"\n";
    for (auto [u,v]:mp){
        cout<<sz(v)<<" ";
        for (auto c:v) cout<<c<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
1
10000000 -2000000000 2000000000 123 321 12312312312 123123123
*/