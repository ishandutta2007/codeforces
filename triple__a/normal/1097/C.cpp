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
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=500007;
const int K=18;
mt19937 rng(time(NULL));

int n;
string s[N];
map<int,int> aaa;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>s[i];
    rep(i,n) {
        int st=0;
        for (auto c:s[i]){
            if (c=='(') st++;
            else st--;
        }
        int ret=0;
        if (st<0) ret=st, st=-st;
        else ret=st, st=0;
        bool ok=1;
        for (auto c:s[i]){
            if (c=='(') st++;
            else st--;
            if (st<0) ok=0;
        }
        if (ok) aaa[ret]++;
    }
    int ans=0;
    for (auto [u,v]:aaa){
        if (u<0) continue;
        if (u==0){
            ans+=v/2;
        }
        else{
            ans+=min(v,aaa[-u]);
        }
    }
    cout<<ans;
    return 0;
}


/*
2
1 2

*/