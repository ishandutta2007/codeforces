#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

int m,h[N];
void prepare(){
    int n,x;
    scanf("%d%d",&n,&m);
    while (n--){
        scanf("%d",&x);
        if (x<N) h[x]=1;
    }
    vector <int> ans;
    REP(i,1,N) if (!h[i]){
        if (i>m) break;
        m-=i;
        ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}