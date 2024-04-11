#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e3+10;

int a[N][N];
int main(){
    int n;
    cin>>n;
    a[0][0]=1;
    REP(pha,0,n){
        int st=1<<pha;
        REP(i,0,st)
            REP(j,0,st){
                a[st+i][j]=a[i][j];
                a[i][st+j]=a[i][j];
                a[st+i][st+j]=a[i][j]^1;
            }
    }
    REP(i,0,1<<n){
        REP(j,0,1<<n) printf("%c",a[i][j]?'+':'*');
        ENDL;
    }
}