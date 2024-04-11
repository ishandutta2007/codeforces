// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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
mt19937 rng(1234);

const int maxn=200007;
const int inf=LLONG_MAX/4;
const int b=1e9;
int n,d0,d1,d2;
int a0,b0,a1,b1;
int query(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int d;
    cin>>d;
    // auto dist=[&](int a,int b,int c,int d){
    //     return abs(a-c)+abs(b-d);
    // };
    // d=min(min(dist(a0,b0,x,y),dist(a0,b1,x,y)),min(dist(a1,b0,x,y),dist(a1,b1,x,y)));
    return d;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15);
    a0=3,b0=3, a1=3,b1=3;
    d0=query(1,1), d1=query(1,1e9), d2=query(1e9,1e9);
    int l=1,r=1e9;
    while (l<r){
        int md=(l+r)>>1;
        int ret=query(1,md+1);
        if (ret-d0==-md) l=md+1;
        else r=md;
    }
    // cout<<l<<endl;
    // cout<<d1<<endl;
    int y0=l, x0=d0-l+2, y1=b+x0-1-d1, x1=2*b-y1-d2;
    cout<<"! "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
    return 0;
}