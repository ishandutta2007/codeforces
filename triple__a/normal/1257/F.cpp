#include<bits/stdc++.h>
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
const int maxn=107;
const int lb=(1<<15)-1;
const int MD1=1e9+7;
const int MD2=998244353;
const int SHA1=84253643;
const int SHA2=19562037;
 
int n;
int a[maxn];
vector<int> vec;
map<vector<int>,int>s;
 
int main(){
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    rep(i,1<<15){
        vec.clear();
        rep(j,n) vec.push_back(__builtin_popcount((a[j]&lb)^i));
        if (s.find(vec)==s.end()) s[vec]=i;
    }
    rep(i,1<<15){
        vec.clear();
        rep(j,n) vec.push_back(-__builtin_popcount((a[j]>>15)^i));
        rep(j,30){
            if (s.find(vec)!=s.end()){
                printf("%d\n",(s[vec])+(i<<15));
                return 0;
            }
            for (auto &c:vec){
                c++;
            }
        }
    }
    printf("-1");
    return 0;
}