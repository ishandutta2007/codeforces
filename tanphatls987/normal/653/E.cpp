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
const int N=3e5+10;

int n,m,k,s[N],h[N];
queue <int> q;
map <int,int> ma[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        ma[x][y]=1;
        ma[y][x]=1;
    }
}
string solve(){
    if (ma[1].size()>n-k-1) return "impossible";
    int n1=n-1,use=0;
    h[1]=1;
    FOR(i,2,n) s[i-1]=i;
    FOR(st,2,n) if (!ma[1].count(st)){
        if (h[st]) continue;
        use++;
        h[st]=1;
        q.push(st);
        while (!q.empty()){
            int x=q.front();q.pop();
            FORD(i,n1,1) {
                if (h[s[i]]){
                    swap(s[i],s[n1--]);
                    continue;
                }
                if (!ma[x].count(s[i])){
                    q.push(s[i]);
                    h[s[i]]=1;
                    swap(s[i],s[n1--]);
                }
            }
        }
    }
//    cout<<use<<'\n';
//    FOR(i,1,n) cout<<h[i]<<" \n"[]
    if (use>k||count(h+1,h+n+1,1)!=n) return "impossible";
    return "possible";
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}