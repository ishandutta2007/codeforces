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

int test,p[N<<1],n;
ii a[N<<1];
bool comp(int x,int y){
    return a[x].X<a[y].X;
}
int main(){
    scanf("%d",&test);
    while (test--){
        scanf("%d",&n);
        ll sum=0;
        REP(i,1,2*n) {
            scanf("%d%d",&a[i].X,&a[i].Y);
            sum+=a[i].Y;
        }
        REP(i,1,2*n) p[i]=i;
        sort(p+1,p+2*n,comp);
        ll cur=0;
        for(int i=1;i<2*n;i+=2) cur+=a[p[i]].Y;
        printf("YES\n");
        if (cur*2>=sum) for(int i=1;i<2*n;i+=2) printf("%d ",p[i]);
        else {
            for(int i=2;i<2*n;i+=2) printf("%d ",p[i]);
            printf("%d ",p[2*n-1]);
        }
        ENDL;
    }
}