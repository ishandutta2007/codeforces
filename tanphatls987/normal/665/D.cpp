#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("edu.inp","r",stdin)
#define OUTPUT freopen("edu.out","w",stdout)
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
const int N=2e6+10;

int h[N],n,a[N];
void prepare(){
    REP(i,2,N) if (!h[i])
        for(int j=i+i;j<N;j+=i) h[j]=1;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    vector <int> ans={a[1]};
    FOR(i,1,n)
        FOR(j,i+1,n) if (!h[a[i]+a[j]]){
            ans={a[i],a[j]};
            break;
        }
    int v=count(a+1,a+n+1,1);
    if (v){
        int sel=0;
        FOR(i,1,n) if (a[i]>1&&!h[a[i]+1]) sel=i;
//        cout<<sel<<'\n';
        if (v+(sel!=0)>int(ans.size())){
            ans=vector<int>(v,1);
            if (sel) ans.push_back(a[sel]);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans) cout<<x<<" ";
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}