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
const int N=2010;

string s,t;
int n,m,f[N][N]={0},d[N];
void solve(){
    REP(i,0,n){
        int st=0;d[i]=0;
        while (i+d[i]<n){
            if (s[i+d[i]]==t[st]) st++;
            if (st==m) break;
            d[i]++;
        }
    }
    //REP(i,0,n) printf("%d ",d[i]);ENDL;
    REP(i,0,n)
        FOR(j,0,min(n,i+1)){
            //printf("%d %d %d %d\n",i,j,i+d[i],j+d[i]+1-m);
            if (j+1<=n) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
            f[i+1][j]=max(f[i+1][j],f[i][j]);
            if (i+d[i]<n&&j+d[i]+1-m<=n&&j<=i)
                f[i+d[i]][j+d[i]+1-m]=max(f[i+d[i]][j+d[i]+1-m],(i?f[i-1][j]+1:1));
    }
    FOR(i,0,n) printf("%d ",f[n-1][i]);
}
int main(){
    cin>>s>>t;
    n=s.length();m=t.length();
    solve();
}