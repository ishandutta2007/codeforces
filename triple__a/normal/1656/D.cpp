// I believe this task appears somewhere before

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=200007;
const int K=18;
mt19937 rng(123);
int n;
int a[N];
int cnt[30];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        int m=n,k=2;
        bool ok=0;
        while (1){
            if (m&1){
                if (k<=2e9&&k*(k+1)<=n*2){
                    cout<<k<<"\n";
                    assert((n-k*(k+1)/2)%k==0);
                    ok=1;
                }
                break;
            }
            m/=2, k*=2;
        }
        if (!ok) {
            if (m>1){
                int p=m;
                // for (int i=2;i*i<=m;++i){
                //     if (m%i==0) {p=i; break;}
                // }
                if (p<=2e9&&p*(p+1)<=n*2) {
                    assert((n-p*(p+1)/2)%p==0);
                    cout<<p<<"\n";
                }
                else cout<<"-1\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
    }
    return 0;
}


/*
10

*/