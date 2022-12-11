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
const int N=1e5+10;

int n,x,y;
vector <int> a[N];
int main(){
    scanf("%d",&n);
    printf("%d\n",n-1);
    FOR(i,1,n-1){
        scanf("%d%d",&x,&y);
        printf("2 %d %d\n",x,y);
        a[x].push_back(i);
        a[y].push_back(i);
    }
    FOR(i,1,n){
        int m=a[i].size();
        REP(j,0,m-1) printf("%d %d\n",a[i][j],a[i][j+1]);
    }
}