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

int b[2][N],f[N],a[N],ma[N],n,m;
ll k;
void add(int *b,int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int *b,int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d%I64d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) ma[i]=a[i];
    sort(ma+1,ma+n+1);
    m=unique(ma+1,ma+n+1)-ma-1;
    FOR(i,1,n) a[i]=lower_bound(ma+1,ma+m+1,a[i])-ma;
    ll sum=0,ans=0;
    FORD(i,n,1){
        f[i]=get(b[1],a[i]-1);
        sum+=f[i];
        add(b[1],a[i],1);
    }
//    FOR(i,1,n) printf("%d ",f[i]);ENDL;
    for(int L=1,R=1;L<n;L++){
        sum+=L-1-get(b[0],a[L])+get(b[1],a[L]-1);
        add(b[0],a[L],1);
        while ((R==L)||(R<=n&&sum>k)){
            sum-=(L-get(b[0],a[R]))+f[R];
            add(b[1],a[R++],-1);
        }
//        printf("%d %d %d\n",L,R,sum);
        ans+=n-R+1;
    }
    cout<<ans;
}