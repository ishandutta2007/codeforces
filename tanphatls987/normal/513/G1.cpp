#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("g.inp","r",stdin)
#define OUTPUT freopen("g.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=10;

int a[N],n,k,bar;
double ans=.0;
int power(int x,int y){
    if (y==0) return 1;
    if (y==1) return x;
    int tmp=power(x,y/2);
    if (y%2) return tmp*tmp*x;
    return tmp*tmp;
}
void DFS(int x){
    if (x>k){
        int sum=0;
        //FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
        FOR(i,1,n)
            FOR(j,1,i) sum+=(a[j]>a[i]);
        ans+=(sum+.0)/bar;
        return;
    }
    FOR(i,1,n)
        FOR(j,i,n){
            for(int L=i,R=j;L<=R;L++,R--) swap(a[L],a[R]);
            DFS(x+1);
            for(int L=i,R=j;L<=R;L++,R--) swap(a[L],a[R]);
        }
}
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    bar=power(n*(n+1)/2,k);
    DFS(1);
    printf("%.10f",ans);
}