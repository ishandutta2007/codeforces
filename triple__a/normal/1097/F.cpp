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
const int N=100007;
const int K=18;
mt19937 rng(time(NULL));
typedef bitset<7003> bs;
int n,q;
bs s[N],t[7007],xx[7007];

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>q;
    for (int i=1;i<=7000;++i){
        int ts=i;
        bool ok=1;
        for (int j=2;j*j<=ts;++j){
            if (ts%(j*j)==0) ok=0;
        }
        if (ok) t[1].set(i,1);
    }
    for (int i=2;i<=7000;++i){
        for (int j=1;i*j<=7000;++j){
            if (t[1].test(j)) t[i].set(i*j,1);
        }
    }
    for (int i=1;i<=7000;++i){
        for (int j=1;i*j<=7000;++j){
            xx[i*j].set(i,1);
        }
    }
    while (q--){
        int op,x,y,v;
        cin>>op;
        if (op==1){
            cin>>x>>v;
            s[x].reset(), s[x]=xx[v];
            // cout<<s[x]<<endl;
        }
        if (op==2){
            cin>>x>>y>>v;
            s[x]=s[y]^s[v];
            // cout<<s[x]<<endl;
        }
        if (op==3){
            cin>>x>>y>>v;
            s[x]=s[y]&s[v];
            // cout<<s[x]<<endl;
        }
        if (op==4){
            cin>>x>>v;
            bs ret=s[x]&t[v];
            // cout<<t[v]<<" "<<s[x]<<endl;
            cout<<(ret.count()&1);
        }
    }
    
    
    return 0;
}


/*
4 13
1 1 1
1 2 4
1 3 6
4 4 4
1 4 4
2 2 1 2
2 3 3 4
4 4 4
3 2 2 3
4 2 1
4 2 2
4 2 3
4 2 4

*/