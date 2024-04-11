#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10,alp=26;

int n,k;
ll g[alp+10];
ii link[alp+10];
string s;
void set_link(int x,int y){
    link[x].Y=y;
    link[y].X=x;
}
void prepare(){
    cin>>n>>k>>s;
}
ll solve(){
    ll sum=1;
    if (k==1) return n+s.length()+1;
    FOR(i,0,k+1) link[i]=ii(i-1,i+1);
    for(auto ch:s){
        int cur=ch-'a'+1;
        ll v=sum;
        sum=(2*sum-g[cur]+MOD)%MOD;
        g[cur]=v;
        set_link(link[cur].X,link[cur].Y);
        set_link(link[k+1].X,cur);
        set_link(cur,k+1);
    }
    while (n--){
        int cur=link[0].Y;
        ll v=sum;
        sum=(2*sum-g[cur]+MOD)%MOD;
        g[cur]=v;
        set_link(link[cur].X,link[cur].Y);
        set_link(link[k+1].X,cur);
        set_link(cur,k+1);
    }
    return sum;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}