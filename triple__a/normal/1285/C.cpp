#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=200007;
int X,ans;
#undef int

int main(){
    scanf("%lld",&X);
    int q=sqrt(X);
    ans=X;
    for (ll i=2;i<=q;++i){
        if (X%i==0&&__gcd(i,X/i)==1){
            ans=X/i;
        }
    }
    printf("%lld %lld\n",X/ans,ans);
    return 0;
}