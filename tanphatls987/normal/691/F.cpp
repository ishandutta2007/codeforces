#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
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
const int N=3e6+10;

int n,n1,a[N];
ii b[N];
ll f[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if (a[i]!=b[n1].X) b[++n1].X=a[i];
        b[n1].Y++;
    }
//    cout<<n1<<'\n';
//    FOR(i,1,n1) cout<<b[i].X<<" "<<b[i].Y<<'\n';
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=i&&1LL*b[i].X*b[j].X<N;j++)
            if (i!=j) f[b[i].X*b[j].X]+=2LL*b[i].Y*b[j].Y;
            else f[b[i].X*b[j].X]+=1LL*b[i].Y*(b[i].Y-1);
    REP(i,1,N) f[i]+=f[i-1];
    int test,val;
    scanf("%d",&test);
    while (test--){
        scanf("%d",&val);
        printf("%lld\n",1LL*n*(n-1)-f[val-1]);
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}