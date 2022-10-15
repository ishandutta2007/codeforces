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
const int N=47;
const int K=18;
mt19937 rng(time(NULL));

int n;
int a[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    for (int i=0;i<(1<<n);++i){
        int sum=0;
        rep(j,n){
            if (i>>j&1) sum+=a[j];
            else sum-=a[j];
        }
        sum=abs(sum);
        if (sum%360==0){
            cout<<"YES";
            return 0;
        } 
    }
    cout<<"NO";
    return 0;
}


/*
2
1 2

*/