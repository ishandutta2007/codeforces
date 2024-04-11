#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

ll h[N];
int a[N];
int main(){
    int m,n=1,type,y,x;
    ll sum=0;
    scanf("%d",&m);
    while (m--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d",&x,&y);
            sum+=1LL*x*y;
            h[x]+=y;
        }
        if (type==2){
            scanf("%d",&x);
            a[++n]=x;
            sum+=x;
        }
        if (type==3){
            sum-=a[n]+h[n];
            h[n-1]+=h[n];
            h[n--]=0;
        }
        printf("%.6f\n",(sum+.0)/n);
    }
}