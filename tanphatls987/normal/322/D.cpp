#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e2+10;

ll f[N][N];
int n,m,c=0,v,b[N],h[N];
ii a[N];
string s;
bool comp(ii x,ii y){
    if (x.X==y.X) return x.Y<y.Y;
    return x.X<y.X;
}
void solve(){
    ll ans=0;
    FOR(i,1,c){
        memset(f,0,sizeof(f));
        FOR(j,1,i)
            FOR(k,1,i){
            if (b[j]>=a[k].Y) f[j][k]=f[j-1][k-1]+b[j]-a[k].Y;
            f[j][k]=max(f[j][k],max(f[j][k-1],f[j-1][k]));
        }
        ans=max(ans,f[i][i]);
    }
    ll go=0;
    int c1=0;
    FOR(i,c+1,n)
        FORD(j,m,1) if (h[j]==0&&b[j]>a[i].Y) {h[j]=1;c1++;break;}
    if (c1==n-c){
        int j=c;
        FOR(i,1,m) if (h[i]==0){
            if (c1==n) {go+=b[i];continue;}
            while (a[j].Y>b[i]&&j) j--;
            if (a[j].Y<=b[i]&&j) go+=b[i]-a[j].Y,c1++,j--;
        }
    }
    if (c1==n) ans=max(ans,go);
    cout<<ans;
}
int main(){
    cin>>n>>m;
    FOR(i,1,n){
        cin>>s>>v;
        if (s=="ATK") c++;
        a[i]=ii(s!="ATK",v);
    }
    sort(a+1,a+n+1,comp);
    FOR(i,1,m) cin>>b[i];
    sort(b+1,b+m+1,greater<int>());
    //FOR(i,1,m) printf("%d\n",b[i]);
    solve();
}