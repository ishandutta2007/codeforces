#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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

int n,m,x,h[N],m1,z[N];
char s[N];
int solve(){
    int last=-inf;
    int ans=1;
    FOR(i,1,n) {
        if (last+m1-1>=i){
            if (h[i]){
                int x=i-last;
                if (z[x]!=m1-x) return 0;
                last=i;
            }
        }else if (!h[i]) ans=(1LL*ans*26)%MOD;
        if (h[i]) last=i;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("\n%s",s);
    FOR(i,1,m) {
        scanf("%d",&x);
        h[x]=1;
    }
    m1=strlen(s);
    z[0]=0;
    int l=0,r=0;
    REP(i,1,m1){
        if (i<r) z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<m1&&s[i+z[i]]==s[z[i]]) z[i]++;
        if (i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    //REP(i,0,m1) cout<<z[i]<<" \n"[i==m1-1];
    cout<<solve();
}