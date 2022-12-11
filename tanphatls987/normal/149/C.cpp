#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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
#define inf 1000000

const int MOD=1000000007;
const int N=100010;

typedef long long ll;
typedef pair<int,int> ii;

int n,v;
ii a[N];
bool found=false;
bool comp(ii x,ii y){
    return x.X<y.Y;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].X);
    FOR(i,1,n) a[i].Y=i;
    sort(a+1,a+n+1);
}
void out(int l,int r){
    printf("%d\n",n-(r-l+1));
    REP(i,1,l) printf("%d ",a[i].Y);
    FOR(i,r+1,n) printf("%d ",a[i].Y);
    printf("\n%d\n",r-l+1);
    FOR(i,l,r) printf("%d ",a[i].Y);
}
void solve(){
    int sum=0,cur=0,l,r,d=0;
    FOR(i,1,n) sum+=a[i].X;
    FOR(i,1,n) d=max(d,a[i].X);
    FOR(i,1,(n/2)) cur+=a[i].X;
    for(l=1,r=n/2;r<=n;){
        if (abs(sum-2*cur)<=d) {found=true;break;}
        else {cur+=a[r+1].X-a[l].X;l++;r++;}
    }
    if (found) {out(l,r);return;}
    cur=0;
    FOR(i,1,(n+1)/2) cur+=a[i].X;
    for(l=1,r=(n+1)/2;r<=n;){
        if (abs(sum-2*cur)<=d) {found=true;break;}
        else {cur+=a[r+1].X-a[l].X;l++;r++;}
    }
    if (found) out(l,r);
}
int main(){
    prepare();
    solve();
}