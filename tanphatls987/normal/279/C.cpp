#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e6+10;

int n,m,x,y,a[N],t[2][N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    a[0]=a[n+1]=-1;
    FOR(i,1,n) t[0][i]=(a[i]<=a[i-1])?t[0][i-1]:i;
    FORD(i,n,1) t[1][i]=(a[i]<=a[i+1])?t[1][i+1]:i;
    while (m--){
        scanf("%d%d",&x,&y);
        if (t[1][x]>=t[0][y]) printf("Yes\n");
        else printf("No\n");
    }
}