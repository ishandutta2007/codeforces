#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=0;

int A,B,n,x,T,m;
int main(){
    scanf("%d%d%d",&A,&B,&n);
    while (n--){
        scanf("%d%d%d",&x,&T,&m);
        if (T<A){
            printf("-1\n");
            continue;
        }
        int L=x,R=(T-A)/B+1;
        while (L<=R){
            int M=(L+R)/2;
            //printf("%d %lld\n",M,1LL*(M-x+1)*A+1LL*(x+M-2)*(M-x+1)/2*B);
            if (1LL*(M-x+1)*A+1LL*(x+M-2)*(M-x+1)/2*B<=1LL*T*m) L=M+1;
            else R=M-1;
        }
        if (R<x) printf("-1\n");
        else printf("%d\n",R);
    }
}