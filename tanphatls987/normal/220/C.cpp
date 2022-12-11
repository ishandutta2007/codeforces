#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10;

int n,p[2][N];
int h[N];
int ans[N];
priority_queue <ii> qd,qi;
vector <int> sw[N];
void prepare(){
    scanf("%d",&n);
    FOR(j,0,1)
        FOR(i,1,n) {
            int x;
            scanf("%d",&x);
            p[j][x]=i;
        }
    FOR(i,1,n) if (p[1][i]>=p[0][i]){
        qi.push(ii(-p[1][i]+p[0][i],i));
        h[i]=1;
        sw[n-p[1][i]+1].push_back(i);
        sw[n-p[1][i]+p[0][i]].push_back(i);
    }
    FORD(i,n,1) if (p[1][i]<p[0][i]){
//        cout<<"tick\n";
        qd.push(ii(p[1][i]-p[0][i],i));
        sw[p[0][i]-p[1][i]].push_back(i);
        sw[n-p[1][i]+1].push_back(i);
    }
}
void solve(){
    REP(turn,0,n){
        for(auto idx:sw[turn]){
//            cout<<turn<<" "<<idx<<'\n';
            if (h[idx]==1) qd.push(ii(-(p[0][idx]-1+turn),idx));
            else qi.push(ii(turn,idx));
            h[idx]^=1;
        }
//        FOR(i,1,n) cout<<h[i]<<" ";ENDL;
        while (!qd.empty()) {
            int idx=qd.top().Y;
            if (h[idx]) qd.pop();
            else{
                int eans=abs(p[0][idx]-(p[1][idx]-1+turn)%n-1);
//                cout<<turn<<" "<<idx<<" "<<eans<<" "<<-qd.top().X-turn<<'\n';
                if (eans!=-qd.top().X-turn) qd.pop();
                else break;
            }
        }
        while (!qi.empty()) {
            int idx=qi.top().Y;
            if (!h[idx]) qi.pop();
            else{
                int eans=abs(p[0][idx]-(p[1][idx]-1+turn)%n-1);
                if (eans!=-qi.top().X+turn) qi.pop();
                else break;
            }
        }
        int cans=n+1;
        if (!qd.empty()) {
            cans=min(cans,-qd.top().X-turn);
//            cout<<turn<<" "<<ans<<" "<<qd.top().Y<<'\n';
        }
        if (!qi.empty()) {
            cans=min(cans,-qi.top().X+turn);
//            cout<<turn<<" "<<ans<<" "<<qi.top().Y<<'\n';
        }
        ans[(n-turn)%n]=cans;
    }
    REP(i,0,n) printf("%d\n",ans[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}