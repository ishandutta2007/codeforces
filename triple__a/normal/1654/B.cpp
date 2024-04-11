// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
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
const int INF=LLONG_MAX/2;
const double EPS=1e-9;
const int N=500007;
const int K=20;
mt19937 rng(1234);


signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        string s;
        cin>>s;
        int n=sz(s);
        int pos[26];
        memset(pos,-1,sizeof(pos));
        rep(i,n) pos[s[i]-'a']=i;
        int mn=INF;
        rep(i,26) if (pos[i]!=-1) mn=min(mn,pos[i]);
        for (int i=mn;i<n;++i) cout<<s[i];
        cout<<"\n";
    }
    return 0;
}