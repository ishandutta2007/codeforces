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
const int N=0;

int a[5],m;
ll sum(int len,int x){
    return 1LL*len*x-1LL*(x+1)*x/2+x;
}
ll cal(int x,int y,int bar,int len){
//    printf("%d %d %d %d\n",x,y,bar,len);
    if (len<0) return 0;
    int R=min(bar-y,len),L=min(len-(bar-x),R);
    ll ans=0;
    if (L>=0) ans+=1LL*(L+1)*(bar-x+1);
    else L=-1;
    ans+=sum(len,R)-sum(len,L);
    return ans;
}
ll solve(int x,int y,int z,int len){
    int tmp=max(max(y,z)+1,x);
    len-=tmp-x;
    x=tmp;
    //
    ll ans=0;
    FOR(i,0,len){
        int cur=x+i,rem=min(2*(cur-1)-y-z,len-i);

        if (rem>cur-y-z) ans+=cal(y,z,cur-1,rem)-cal(y,z,cur-1,(cur-y-z));
//        printf("%d %d %d %d %lld\n",cur,y,z,rem,ans);
    }
    return ans;
}
ll solve2(int x,int y,int z,int len){
    int tmp=max(x,y);
    len-=2*tmp-x-y;
    x=tmp;
    if (x<=z) len-=2*(z+1-x),x=z+1;
    ll ans=0;
//    printf("%d %d %d\n",x,len,z);
    if (len>=0) FOR(i,0,len/2){
        int rem=len-2*i;
        ans+=min(x+i-1-z,rem)+1;
    }
    return ans;
}
int main(){
    FOR(i,0,2) cin>>a[i];
    cin>>m;
    ll ans=0;
    FOR(i,0,2) ans+=solve(a[i],a[(i+1)%3],a[(i+2)%3],m);
//    cout<<ans<<'\n';
    FOR(i,0,2) ans+=solve2(a[i],a[(i+1)%3],a[(i+2)%3],m);
    //all equal
    int tmp=*max_element(a,a+3),v=0;
    FOR(i,0,2) v+=tmp-a[i];
    if (v<=m) ans+=(m-v)/3+1;
    //
    cout<<ans;
}