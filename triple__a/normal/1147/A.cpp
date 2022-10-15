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
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=200007;
const int K=207;
mt19937 rng(time(NULL));

typedef bitset<300> bs;
int n,k;
int a[N],fst[N],lst[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>k;
    rep1(i,n) fst[i]=INF, lst[i]=0;
    rep1(i,k) cin>>a[i];
    rep1(i,k) lst[a[i]]=i;
    for (int i=k;i>0;--i) fst[a[i]]=i;
    int cnt=0;
    for (int i=1;i<=n;++i){
        if (i>1&&fst[i]>lst[i-1]) cnt++;
        if (i<n&&fst[i]>lst[i+1]) cnt++;
        if (fst[i]==INF) cnt++;
    }
    cout<<cnt;
    return 0;
}


/*
5
0 0
4 0
0 4
4 4
2 3


*/