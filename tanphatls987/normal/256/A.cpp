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
const int N=4e3+10;

int n,a[N],p[N],f[N],last[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=a[i];
    sort(p+1,p+n+1);
    int m=unique(p+1,p+n+1)-p-1;
    FOR(i,1,n) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
    int ans=0;
    FOR(sel,1,m){
        memset(f,0,sizeof(f));
        memset(last,0,sizeof(last));
        ans=max(ans,count(a+1,a+n+1,sel));
        FOR(i,1,n){
            if (last[sel]>last[a[i]]) f[a[i]]+=2;
            last[a[i]]=i;
//            printf("%d %d %d\n",sel,a[i],f[a[i]]);
        }
        FOR(i,1,m) ans=max(ans,f[i]+(last[sel]>last[i]));
    }
    cout<<ans;
}