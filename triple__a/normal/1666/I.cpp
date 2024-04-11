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
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
// const int mod=1e9+7;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=25007;
const int K=360*10000;
mt19937 rng(1234);

int n,m;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>m;
        auto query=[&](int x,int y){
            cout<<"SCAN "<<x<<" "<<y<<endl;
            int u;
            cin>>u;
            return u;
        };
        auto ret1=query(1,1);
        auto ret2=query(n,1);
        ret1+=4, ret2+=2-2*n;
        int sumy=(ret1+ret2)/2, sumx=ret1-sumy;
        auto ret3=query(sumx/2,1)+2;
        int x1=(ret1-ret3)/2,x2=sumx-x1;
        auto ret4=query(1,sumy/2)+1;
        int y1=(ret1-ret4)/2, y2=sumy-y1;
        cout<<"DIG "<<x1<<" "<<y1<<endl;
        int aaa;
        cin>>aaa;
        if (aaa==1){
            cout<<"DIG "<<x2<<" "<<y2<<endl;
            int u;
            cin>>u;
            assert(u==1);
        }
        else{
            cout<<"DIG "<<x1<<" "<<y2<<endl;
            int u;
            cin>>u;
            assert(u==1);
            cout<<"DIG "<<x2<<" "<<y1<<endl;
            cin>>u;
            assert(u==1);
        }
    }
    return 0;
}