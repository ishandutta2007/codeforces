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

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,k,p[N],a[N],x;
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,0,n) {
        scanf("%d",a+i);
        p[a[i]]=i;
    }
}
int main(){
    prepare();
    ll ans=0;
    while (m--){
        scanf("%d",&x);
        ans+=(p[x]/k)+1;
        if (p[x]){
            int pos=p[x];
            swap(a[pos],a[pos-1]);
            p[a[pos-1]]=pos-1;
            p[a[pos]]=pos;
        }
    }
    cout<<ans;
}