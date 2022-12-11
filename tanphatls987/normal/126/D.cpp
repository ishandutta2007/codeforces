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

const ll inf=1e18;
const int MOD=1e9+7;
const int N=0;

ll fib[100],f[100][3],s[100],x;
int n,test;
int get(int dist){
    if (dist<=0) return 0;
    return (dist+1)/2;
}
ll solve(ll x){
    int m=0;
    FORD(i,n,1) if (x>=fib[i]){
        s[++m]=i;
//        printf("%d ",i);
        x-=fib[i];
    }
//    ENDL;
    f[m][0]=get(s[m]-2);
    f[m][1]=1;
    FORD(i,m-1,1){
        f[i][0]=f[i+1][0]*get(s[i]-s[i+1]-1)+f[i+1][1]*get(s[i]-s[i+1]-2);
        f[i][1]=f[i+1][1]+f[i+1][0];
    }
    return f[1][0]+f[1][1];
}
void prepare(){
    fib[0]=fib[1]=1;
    n=1;
    while (inf-fib[n]>=fib[n-1]) ++n,fib[n]=fib[n-1]+fib[n-2];
}
int main(){
    prepare();
    scanf("%d",&test);
    while (test--){
        scanf("%I64d",&x);
        printf("%I64d\n",solve(x));
    }
}