// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
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
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=1e9+7;
const double EPS=1e-9;
// const double pi=acos(-1);
const int INF=1e18;
const int N=200007;
mt19937 rng(1231);

int n;
int p[2*N],q[2*N];
int a[4][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n;
    rep(_,4) rep(i,n) cin>>a[_][i];
    queue<int> A[4];
    int ans=0;
    rep(i,n){
        rep(j,4) if (a[j][i]) A[j].push(i);
        if (sz(A[0])&&sz(A[2])){
            ans+=abs(A[0].front()-A[2].front());
            A[0].pop(), A[2].pop();
        }
        if (sz(A[1])&&sz(A[3])){
            ans+=abs(A[1].front()-A[3].front());
            A[1].pop(), A[3].pop();
        }
        if (sz(A[0])&&sz(A[3])){
            ans+=abs(A[0].front()-A[3].front())+1;
            A[0].pop(), A[3].pop();
        }
        if (sz(A[1])&&sz(A[2])){
            ans+=abs(A[1].front()-A[2].front())+1;
            A[1].pop(), A[2].pop();
        }
    }
    rep(i,4) if (sz(A[i])) return cout<<-1,0;
    cout<<ans;
    return 0;
}
/*

*/