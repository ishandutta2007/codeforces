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
const int N=2e5+10;


int n,a[N],h[N];
map <ii,int> ma;
bool check(int idx){
    if (idx&1) return a[idx]<min(a[idx-1],a[idx+1]);
    return a[idx]>max(a[idx+1],a[idx-1]);
}
bool inrange(int idx){
    return (idx<=n&&idx>0);
}
int sweep(int xa,int ya,int xb,int yb){
    int ans=0;
    if (xa>xb) swap(xa,xb),swap(ya,yb);
    if (xa<=xb&&xb<=ya){
        FOR(i,xa,yb) if (inrange(i)){
            h[i]=check(i);
            ans+=h[i];
        }
        return ans;
    }
    FOR(i,xa,ya) if (inrange(i)) h[i]=check(i),ans+=h[i];
    FOR(i,xb,yb) if (inrange(i)) h[i]=check(i),ans+=h[i];
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    a[0]=inf;
    a[n+1]=(n&1)?inf:-1;
}
int solve(){
    FOR(i,1,n) h[i]=check(i);
    int st=1;
    while (h[st]) st++;
    int n1=count(h+1,h+n+1,1);
    FOR(pha,-1,1) if (inrange(st+pha)){
        int sel=st+pha;
        FOR(i,1,n) if (i!=sel){
            swap(a[sel],a[i]);
            int cur=n1+sweep(i-1,i+1,sel-1,sel+1);
            swap(a[sel],a[i]);
            cur-=sweep(i-1,i+1,sel-1,sel+1);
            if (cur==n){
                ii nx=ii(i,sel);
                if (nx.X>nx.Y) swap(nx.X,nx.Y);
                ma[nx]=1;
            }
        }
    }
    return ma.size();
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}