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
const ll linf=1e16;
const int MOD=1e9+7;
const int N=2e5+10;

int cap,n;
ii a[N];
ll f[N];
int s[N];
void prepare(){
    int ep;
    scanf("%d%d%d",&ep,&cap,&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    a[++n]=ii(ep,-1);
    sort(a+1,a+n+1);
//    FOR(i,0,n) cout<<a[i].X<<" "<<a[i].Y<<'\n';
}
ll solve(){
    int top=1;
    s[1]=n;
    FORD(i,n-1,0){
        int L=1,R=top;
        int reachable=a[i].X+cap;
        while (L<=R){
            int mid=(L+R)/2;
            if (a[s[mid]].X>reachable) L=mid+1;
            else R=mid-1;
        }
        f[i]=linf;
        if (L>top) continue;
        ///
        int sL=L,sR=top;
        while (sL<=sR){
            int smid=(sL+sR)/2;
            if (a[s[smid]].Y>=a[i].Y) sR=smid-1;
            else sL=smid+1;
        }
        int idx=s[max(sR,L)];
//        cout<<i<<" "<<reachable<<" "<<s[L]<<'\n';

        int dist=a[idx].X-a[i].X,rem=cap-dist;
        if (a[i].Y>a[idx].Y) f[i]=min(f[i],f[idx]+1LL*dist*a[i].Y);
        else f[i]=min(f[i],f[idx]+1LL*cap*a[i].Y-1LL*rem*a[idx].Y);
        while (a[i].Y<=a[s[top]].Y) top--;
        s[++top]=i;
    }
    if (f[0]==linf) return -1;
    return f[0];
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}