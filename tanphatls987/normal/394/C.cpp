#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

int n,m,h[3],a[N<<1][N];
string s;
void fillin(int i,int j){
    if (h[2]) a[j][i]=a[j+1][i]=1,h[2]--;
    else if (h[1]){
        int col=(a[j][i-1]);
        a[j+col][i]=1;
        h[1]--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m) {
            cin>>s;
            h[count(s.begin(),s.end(),'1')]++;
        }
    FOR(i,1,n) if (i&1)
        for(int j=1;j<=2*m;j+=2) fillin(i,j);
        else for(int j=2*m-1;j>=1;j-=2) fillin(i,j);
    FOR(i,1,n) {
        for(int j=1;j<=2*m;j+=2) printf("%d%d ",a[j][i],a[j+1][i]);
        ENDL;
    }
}