#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

priority_queue <ll> q;
ll cur,ans[N];
int n,m,p[N];
ii a[N];
bool comp(int x,int y){
    return a[x].X<a[y].X;
}
void relax(){
    while (!q.empty()&&-q.top()<=cur){
        q.pop();m++;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    FOR(i,1,n){
        int x=p[i];
        cur=max(cur,ll(a[x].X));
        relax();
//        printf("%d %lld %d\n",m,cur,x);
        if (!m) {
            cur=-q.top();
            relax();
        }
        ans[x]=cur+a[i].Y;
        q.push(-ans[x]);m--;
    }
    FOR(i,1,n) printf("%I64d\n",ans[i]);
}