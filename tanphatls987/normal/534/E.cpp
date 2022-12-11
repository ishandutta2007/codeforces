#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1
#define EXT {printf("-1");return;}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int h[N]={0},d[N],n,m,x;
ll solve(){
    if (h[1]==h[n]){
        if (n==1) return 0;
        //if (n==2) return 1LL*(2*h[1]-1)*(d[n]-d[1]);
        int v=max(0,2*h[1]-1);
        if (count(h+2,h+n,v+1)==n-2){
            FOR(i,2,n-1) if (d[i]-d[i-1]!=d[i+1]-d[i]) return -1;
            return 1LL*(v+1)*(d[n]-d[1])-(d[2]-d[1]);
        }
        int L=1,R=n;
        if (v==0){
            while (h[L]==0) L++;
            while (h[R]==0) R--;
            return d[R]-d[L];
        }
        while (h[L+1]==v+1) L++;
        while (h[R-1]==v+1) R--;
        if (h[L+1]==v+2) return d[n]-d[L+1]+d[R-1]-d[1]+1LL*v*(d[n]-d[1]);
        return 1LL*v*(d[n]-d[1])+d[L]-d[1]+d[n]-d[R];
    }else if (h[1]>h[n]){
        int v=h[1]+h[n]-1;
        int L=1,R=1;
        while (h[L+1]==v+2) L++;
        while (h[R+1]>=v+1) R++;
        return 1LL*v*(d[n]-d[1])+d[L]-d[1]+d[R]-d[1];
    }else{
        int v=h[1]+h[n]-1;
        int L=n,R=n;
        while (h[L-1]==v+2) L--;
        while (h[R-1]>=v+1) R--;
        return 1LL*v*(d[n]-d[1])+d[n]-d[L]+d[n]-d[R];
    }
}
int main(){
    //INPUT;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",d+i);
    scanf("%d",&m);
    while (m--){
        scanf("%d",&x);
        h[x]++;
    }
    //FOR(i,1,n) cout<<h[i]<<" \n"[i==n];
    cout<<solve();
}