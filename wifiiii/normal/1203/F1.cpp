#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

int a[105],b[105];
int main() {
    int n,r;
    cin>>n>>r;
    ii cin>>a[i]>>b[i];
    vector<int> ord(n);
    iota(all(ord),1);
    sort(all(ord),[&](int i,int j){
        if(b[i]>=0 && b[j]>=0) {
            return a[i]<a[j];
        }
        if(b[i]*b[j]<=0) return b[i]>=0;
        return a[j]-b[i]<a[i]-b[j];
    });
    // (ai, bi)
    // (aj, bj)
    // r >= ai, r += bi
    // r + bi >= aj, r += bi + bj
    // r >= aj - bi (i, j) = 1
    // r >= ai - bj
    int ok=1;
    for(int x:ord) {
        if(r<a[x]) ok=0;
        r+=b[x];
    }
    if(r<0) ok=0;
    if(ok) puts("YES");
    else puts("NO");
}