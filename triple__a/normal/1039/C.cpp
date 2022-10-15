#include<bits/stdc++.h>
#define ULL unsigned long long
#define int long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()

using namespace std;

typedef long long ll;

const int mod=1e9+7;
const int maxn=500007;
int n,m,k,p[maxn],ans=0,pw[maxn];
int val[maxn];
pair<int,int> e[maxn];

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}

int calc(pair<int,int> p){
    return val[p.F]^val[p.S];
}

bool cmp(pair<int,int> u,pair<int,int> v){
    return calc(u)<calc(v);
}

#undef int
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    ULL ret=(1ULL<<k);
    rep1(i,n) scanf("%lld",&val[i]);
    pw[0]=1;
    rep1(i,n) pw[i]=2*pw[i-1]%mod;
    rep1(i,n) p[i]=i;
    rep1(i,m) scanf("%lld%lld",&e[i].F,&e[i].S);
    sort(e+1,e+m+1,cmp);
    int i=1;
    vector<int> vec;
    while (i<=m){
        int tmp=0;
        ret--;
        vec.clear();
        while (i<m&&calc(e[i])==calc(e[i+1])){
            vec.push_back(e[i].F), vec.push_back(e[i].S);
            tmp+=unite(e[i].F,e[i].S);
            i++;
        }
        vec.push_back(e[i].F),vec.push_back(e[i].S);
        tmp+=unite(e[i].F,e[i].S);
        i++;
        for (auto c:vec){
            p[c]=c;
        }
 //       cout<<pw[n-tmp]<<endl;
        ans=(ans+pw[n-tmp])%mod;
    }
    ret=ret%mod;
    ans=(ans+pw[n]*ret)%mod;
    printf("%lld",ans);
    return 0;
}