#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=3e5+10;

int a[N],t[N];
void prepare(){
    int n,m,L,R,x;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FORD(i,n,1) if (a[i]!=a[i+1]) t[i]=i+1;
    else t[i]=t[i+1];
    while (m--){
        scanf("%d%d%d",&L,&R,&x);
        if (a[L]!=x) printf("%d\n",L);
        else printf("%d\n",t[L]<=R?t[L]:-1);
    }
}
int main(){
    prepare();

}