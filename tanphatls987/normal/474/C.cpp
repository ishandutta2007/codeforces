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

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=10;

ii a[10],b[10],r[10];
ll d[10];
void prepare(){
    FOR(i,0,3) scanf("%d%d%d%d",&a[i].X,&a[i].Y,&b[i].X,&b[i].Y);
}
void change(int idx,int v){
    r[idx]=a[idx];
    FOR(i,1,v) r[idx]=ii(b[idx].X+(b[idx].Y-r[idx].Y),b[idx].Y-(b[idx].X-r[idx].X));
}
bool check(){
    int top=0;
    FOR(i,0,2)
        FOR(j,i+1,3) d[++top]=1LL*(r[i].X-r[j].X)*(r[i].X-r[j].X)+1LL*(r[i].Y-r[j].Y)*(r[i].Y-r[j].Y);
    sort(d+1,d+top+1);
    int l1=1;
    while (d[l1+1]==d[l1]&&l1<top) l1++;
    int l2=l1+1;
    while (d[l2+1]==d[l2]&&l2<top) l2++;
    if (l1==4&&l2==6&&d[l1]*2==d[l2]) return true;
    return false;
}
void solve(){
    int ans=inf;
    REP(k,0,1<<8){
        int mov=0,v=k;
        FOR(i,0,3) mov+=v%4,change(i,v%4),v>>=2;
        if (check()) ans=min(ans,mov);
    }
    printf("%d\n",(ans==inf)?-1:ans);
}
int main(){
    int test;
    scanf("%d",&test);
    while (test--){
        prepare();
        solve();
    }
}