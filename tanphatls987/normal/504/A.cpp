#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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

int n,d[N],w[N];
int main(){
    queue <int> q;
    scanf("%d",&n);
    int e=0;
    REP(i,0,n){
        scanf("%d%d",d+i,w+i);
        if (d[i]==1) q.push(i);
        e+=d[i];
    }
    printf("%d\n",e>>1);
    while (!q.empty()){
        int x=q.front();q.pop();
        if (!d[x]) continue;
        d[w[x]]--;
        d[x]--;
        printf("%d %d\n",x,w[x]);
        if (d[w[x]]==1) q.push(w[x]);
        w[w[x]]^=x;
    }
}