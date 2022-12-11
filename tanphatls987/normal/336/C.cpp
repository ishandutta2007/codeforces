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

int n,a[N];
int check(int x){
    int c=0,v=(1LL<<x)-1;
    FOR(i,1,n) if (a[i]&(1<<x)) v&=a[i],c++;
    return (v==0)?c:0;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FORD(i,29,0){
        int v=check(i);
        if (v){
            printf("%d\n",v);
            FOR(j,1,n) if (a[j]&(1<<i)) printf("%d ",a[j]);
            return 0;
        }
    }
}