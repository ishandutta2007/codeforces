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

int n,L,R,mid,a[N],h[N];
bool check(int cM){
    memset(h,0,sizeof(h));
    if (cM<=n/2){
        FOR(i,L,cM) h[a[i]]++,h[a[n-i+1]]--;
    }else{
        FOR(i,L,n-L+1) {
            if (i<=cM) h[a[i]]++;
            else h[a[i]]--;
        }
    }
    FOR(i,1,n) if (h[i]<0) return 0;
    return 1;
}
ll solve(){
    ll ans=0;
    ///it can't be!
    FOR(i,1,n) h[a[i]]^=1;
    if (count(h+1,h+n+1,1)!=n%2) return 0;
    //
    mid=(n+1)>>1,L=1,R=mid;
    while (R&&a[R]==a[n-R+1]) R--;
    ///palindrome by default
    if (!R) return 1LL*n*(n+1)/2;
    //
    while (L<=mid&&a[L]==a[n-L+1]) L++;
    int cL=R,cR=n-L+1;
    while (cL<=cR){
        int cM=(cL+cR)>>1;
        if (check(cM)) cR=cM-1;
        else cL=cM+1;
    }
    ans+=1LL*L*(n-cL+1);
//    cout<<L<<" "<<R<<" "<<cL<<'\n';
    ///
    memset(h,0,sizeof(h));
    FOR(i,L+1,n-L+1) h[a[i]]++;
    if ((--h[a[L]])>=0) FOR(i,L+1,mid){
        ans+=L;
        h[a[i]]-=2;
        if (h[a[i]]<0) break;
    }
    memset(h,0,sizeof(h));
    FOR(i,L,R) h[a[i]]++,h[a[n-i+1]]--;
    bool ok=1;
    FOR(i,1,n) if (h[i]<0) ok=0;
    if (ok) ans+=1LL*(n-R+1-mid)*L;
    return ans;
}
int main(){
//    INPUT;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    cout<<solve();
}