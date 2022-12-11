#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e6;

ll h[N+5];
int t[N+5];
int main(){
    FOR(i,1,N) t[i]=i;
    FOR(i,2,N) if (t[i]==i)
        for(int j=i;j<=N;j+=i)
            while (t[j]%i==0) t[j]/=i,h[j]++;
    FOR(i,1,N) h[i]+=h[i-1];
    int test,x,y;
    scanf("%d",&test);
    while (test--){
        scanf("%d%d",&y,&x);
        printf("%I64d\n",h[y]-h[x]);
    }
}