#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10;

int n,m,k,p[N];
ii a[N];
ll g[N];
priority_queue <int> q;
bool comp(int x,int y){
    return (a[x].X==a[y].X)?a[x].Y>a[y].Y:a[x].X<a[y].X;
}
bool comp2(int x,int y){
    return (a[x].Y==a[y].Y)?a[x].X>a[y].X:a[x].Y>a[y].Y;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d%d",&a[i].Y,&a[i].X);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    FOR(i,1,n) g[i]=g[i-1]+a[p[i]].X;
    int pos=0;
    ll ans1=-1,ans2=-1,cans1=0;
    k=m-k;
    REP(i,0,m-k){
        q.push(-a[p[n-i]].Y);
        cans1+=a[p[n-i]].Y;
    }
    FORD(i,n-m,0){
//        printf("%d %lld %lld\n",i,cans1,g[i+k]-g[i]);
        if (cans1>ans1||(cans1==ans1&&g[i+k]-g[i]>ans2)){
            pos=i+1;
            ans1=cans1;
            ans2=g[i+k]-g[i];
        }
        int v=-q.top();
        if (a[p[i+k]].Y>v){
            cans1+=a[p[i+k]].Y-v;
            q.pop();
            q.push(-a[p[i+k]].Y);
        }
    }
    sort(p+pos+k,p+n+1,comp2);
    REP(i,pos,pos+m) printf("%d ",p[i]);
}