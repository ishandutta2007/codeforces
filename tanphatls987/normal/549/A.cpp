#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=60;
const string St="face";

int a[N][N],h[6],n,m;
char s[N];
int cv(char c){
    REP(i,0,4) if (c==St[i]) return i+1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=cv(s[j-1]);
    }
    int ans=0;
    REP(i,1,n)
        REP(j,1,m){
            memset(h,0,sizeof(h));
            h[a[i][j]]++;
            h[a[i+1][j]]++;
            h[a[i][j+1]]++;
            h[a[i+1][j+1]]++;
            if (count(h+1,h+5,1)==4) ans++;
        }
    cout<<ans;
}