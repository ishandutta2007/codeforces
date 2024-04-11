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

const int MOD=1e9+7;
const int N=1e5+10,M=1e3+10;

typedef long long ll;

int n,m,z[2][N+M];
string s,a[110],t;
void prepare(){
    cin>>s>>m;
    n=s.length();
    FOR(i,1,m) cin>>a[i];
}
void z_func(int k){
    int d=t.length();
    for(int i=1,r=0,l=0;i<d;i++){
        if (i<=r) z[k][i]=min(z[k][i-l],r-i+1);else z[k][i]=0;
        while (t[i+z[k][i]]==t[z[k][i]]) z[k][i]++;
        if (i+z[k][i]-1>r) l=i,r=i+z[k][i]-1;
    }
}
void solve(){
    int ans=0;
    FOR(i,1,m){
        memset(z,0,sizeof(z));
        int d=a[i].length();
        if (d<2) continue;
        t=a[i]+'*'+s;
        z_func(0);
        REP(j,0,d) t[j]=a[i][d-j-1];
        REP(j,0,n) t[d+j+1]=s[n-j-1];
        z_func(1);
        //FOR(k,0,1) {FOR(j,d+1,d+n) printf("%d ",z[k][j]);ENDL;}
        FOR(k,0,1) FOR(j,d+1,d+n) z[k][j]=max(z[k][j],z[k][j-1]);
        FOR(j,0,n-d) if (z[0][d+j]+z[1][d+(n-(d+j-1))]>=d) {ans++;break;}
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}