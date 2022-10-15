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
const double pi=acos(-1);
const int INF=1e18;
const int N=507;
mt19937 rng(1235);
const int M=30;

int n,x;
int a[N],sum[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    int n,m;
    cin>>n>>m;
    string s(m,'0');
    auto query=[&](string& s){
        cout<<"? "<<s<<endl;
        int u;
        cin>>u;
        return u;
    };
    vector<pii> e;
    rep(i,m){
        s[i]='1';
        auto ret=query(s);
        s[i]='0';
        e.pb({ret,i});
    }
    sort(range(e));
    int sum=0;
    for (auto [x,y]:e){
        sum+=x;
        s[y]='1';
        auto ret=query(s);
        if (sum!=ret) sum-=x, s[y]='0';
    }
    cout<<"! "<<sum<<endl;
    
    return 0;
}
/*

*/