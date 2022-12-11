#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

char s[N];
int h[N][3],c[3],p[3],m,x,y;
bool ok(int L,int R){
    if (R-L+1<3) return 1;
    FOR(j,0,2) c[j]=h[R][j]-h[L-1][j];
    FOR(j,0,2) p[j]=j;
    do{
        bool cok=1;
        FOR(j,0,2) if (c[p[j]]!=(R-L+3-j)/3) cok=0;
        if (cok) return 1;
    }while (next_permutation(p,p+3));
    return 0;
}
int main(){
    scanf("%s",s);
    scanf("%d",&m);
    int n=strlen(s);
    FOR(i,1,n){
        FOR(j,0,2) h[i][j]=h[i-1][j];
        h[i][s[i-1]-'x']++;
    }
    while (m--){
        scanf("%d%d",&x,&y);
        if (ok(x,y)) printf("YES\n");
        else printf("NO\n");
    }
}