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
const int N=0;

int n,m,k;
int main(){
    cin>>n>>m>>k;
    ll ans=0;
    FOR(xa,0,(n-1)/2)
        FOR(ya,0,(m-1)/2){
            int S=(2*xa+1)*(2*ya+1);
            if (S>k) break;
            if (S==k) ans+=1LL*(n-2*xa)*(m-2*ya)*(2LL*(xa+1)*(ya+1)-1);
            else{
                if ((k-S)&1) continue;
                S=(k-S)>>1;
                FOR(xb,xa+1,(n-1)/2){
                    if (S%(xb-xa)) continue;
                    int yb=S/(xb-xa);
                    //printf("%d %d %d %d\n",xa,ya,xb,yb);
                    if (yb%2==0) continue;
                    yb>>=1;
                    if (yb>=ya) continue;
//                    printf("%d %d %d %d\n",xa,ya,xb,yb);
                    ans+=2LL*(n-2*xb)*(m-2*ya);
                }
            }
        }
    cout<<ans;
}