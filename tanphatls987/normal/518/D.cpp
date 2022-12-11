#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e3+10;

double c[N][N],pro;
int n,m;
double solve(){
    c[0][0]=1.0;
    FOR(i,1,m){
        c[i][0]=(1-pro)*c[i-1][0];
        FOR(j,1,min(m,n)) c[i][j]=((j==n)?1:(1-pro))*c[i-1][j]+pro*c[i-1][j-1];
    }
    double ans=0;
    FOR(i,0,min(m,n)) ans+=c[m][i]*i;
    return ans;
}
int main(){
    cin>>n>>pro>>m;
    printf("%.7f\n",solve());
    //FOR(i,1,m)
        //FOR(j,0,i) cout<<c[i][j]<<" \n"[j==i];
}