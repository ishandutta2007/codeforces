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
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=10;
const int c[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

typedef long long ll;

struct cube{
    int p[3];
    void read(){
        scanf("%d%d%d",&p[0],&p[1],&p[2]);
    }
};
ll d[30];
cube a[N],ncub[N];
bool checkcub(){
    int top=0;
    memset(d,0,sizeof(d));
    FOR(i,1,7) FOR(j,i+1,8) {top++;FOR(k,0,2) d[top]+=1LL*(ncub[j].p[k]-ncub[i].p[k])*(ncub[j].p[k]-ncub[i].p[k]);}
    ll dis=(*min_element(d+1,d+top+1));
    return (count(d+1,d+top+1,dis)==12&&count(d+1,d+top+1,(dis*2))==12&&count(d+1,d+top+1,(dis*3))==4);
}
bool make(int idx){
    if (idx>8) return checkcub();
    FOR(i,0,5){
        FOR(j,0,2) ncub[idx].p[j]=a[idx].p[c[i][j]];
        if (make(idx+1)) return true;
    }
    return false;
}
void solve(){
    ncub[1]=a[1];
    if (make(2)) {printf("YES\n");FOR(i,1,8) {FOR(j,0,2) printf("%d ",ncub[i].p[j]);ENDL;};return;}
    printf("NO");
}
int main()
{
    FOR(i,1,8) a[i].read();
    solve();
}