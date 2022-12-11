#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1
#define FAIL {printf("-1");return;}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int n,dia,hei;
void solve(){
    if (2*hei<dia) FAIL;
    int rem=n-hei-1;
    if (hei==1&&dia==1&&rem) FAIL;
    FOR(i,1,hei) printf("%d %d\n",i,i+1);
    if (dia>hei){
        printf("1 %d\n",hei+2);
        FOR(i,2,dia-hei) printf("%d %d\n",hei+i,hei+i+1);
    }
    FOR(i,dia+2,n) printf("%d %d\n",i,hei);
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>n>>dia>>hei;
    solve();
}