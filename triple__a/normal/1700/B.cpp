// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
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
mt19937 rng(1235);

string s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    int _;
    cin>>_;
    while (_--){
        int n;
        cin>>n>>s;
        if (s[0]!='9'){
            for (auto c:s){
                cout<<9-(c-'0');
            }
            cout<<"\n";
            continue;
        }
        vi tmp;
        bool aaa=0;
        reverse(range(s));
        for (auto c:s){
            int a=1-aaa, b=c-'0';
            if (b<=a) aaa=0, tmp.pb(a-b);
            else aaa=1, tmp.pb(10+a-b);
        }
        reverse(range(tmp));
        for (auto c:tmp) cout<<c;
        cout<<"\n";
    }
    return 0;
}
/*

*/