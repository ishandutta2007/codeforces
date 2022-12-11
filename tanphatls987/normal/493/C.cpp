#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9+500;
const int MOD=1e9+7;
const int N=2e5+10;

int a[N],b[N],n,m;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",b+i);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
}
int main(){
    prepare();
    int ansa=0,ansb=inf;
    a[n+1]=inf;
    FOR(i,0,n){
        while (i<n&&a[i+1]==a[i]) i++;
        int sc1=2*i+3*(n-i),pos=upper_bound(b+1,b+m+1,a[i+1]-1)-b,sc2=2*(pos-1)+3*(m-pos+1);
        if (sc1-sc2>ansa-ansb) ansa=sc1,ansb=sc2;
        else if (sc1-sc2==ansa-ansb&&sc1>ansa) ansa=sc1,ansb=sc2;
    }
    printf("%d:%d",ansa,ansb);
}