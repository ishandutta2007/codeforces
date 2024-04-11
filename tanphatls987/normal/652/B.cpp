#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("mdraft.inp","r",stdin)
#define OUTPUT freopen("mdraft.out","w",stdout)
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
const int N=1e6+10;

int n,a[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int pha=1,i=1,j=n;pha<=n;pha++) if (pha&1) printf("%d ",a[i++]);
    else printf("%d ",a[j--]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}