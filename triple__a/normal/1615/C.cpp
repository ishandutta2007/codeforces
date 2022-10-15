// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>

#define int long long
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=LLONG_MAX/4;
const int maxn=1000007;
const double EPS=1e-9;
int _;
int n;
string s,t;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>_;
    while (_--){
        cin>>n;
        cin>>s>>t;
        int same[]={0,0}, diff[]={0,0};
        for (int i=0;i<n;++i){
            if (s[i]==t[i]) same[s[i]-'0']++;
            else diff[s[i]-'0']++;
        }
        int ans=n+7;
        if (((same[0]+same[1])&1)&&same[1]-same[0]==1){
            ans=min(ans,same[0]+same[1]);
        }
        if ((diff[0]+diff[1])%2==0&&(diff[1]==diff[0])) ans=min(ans,diff[0]+diff[1]);
        if (ans>n) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}

/*
5 3 
3 0 2 3 
3 3 0 1
4 0 1 3 4

2 0 3 1 4

1 0 3 4 
*/