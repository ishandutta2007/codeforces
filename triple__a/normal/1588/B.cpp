// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
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
 
 
const int maxn=200007;
const int mod=998244353;
const double pi=3.1415926535;

int n,k;
int sum;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    auto query=[&](int u,int v){
        cout<<"? "<<u<<" "<<v<<endl;
        int w;
        cin>>w;
        return w;
    };
    auto mysqrt=[&](int u)->int{
        int w=sqrt(u)-2;
        for (int i=0;i<=6;++i){
            if (w+i>=0&&(w+i)*(w+i)==u) return w+i;
        }
        assert(0);
        return -1;
    };
    while (_--){
        cin>>n;
        sum=query(1,n);
        int l=1,r=n;
        while (l<r){
            int md=(l+r)>>1;
            if (!query(1,md)) l=md+1;
            else r=md;
        }
        l--;
        int fk=query(l+1,n);
        int len1=sum-fk+1;
        int aaa=query(l+len1,n);
        int www=(mysqrt(8*aaa+1)+1)/2;
        cout<<"! "<<l<<" "<<l+len1<<" "<<l+len1+www-1<<endl;
    }
    return 0;
}