#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1
#define WRONG {printf("-1");return ;}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int n,m;
void solve(){
    if (m==3&&n>4) WRONG;
    if (m==4&&n==8){
        printf("0 0\n0 1\n1 1\n1 0\n-1 -2\n-1 3\n2 -2\n2 3\n");
        return;
    }
    printf("100000 1000\n");
    REP(i,1,m) printf("%d %d\n",100000+i*(i+1)/2,1000-i);
    if (n-m){
        int dec=(n==2*m)?1:0;
        if (dec) printf("100000 0\n");
        FOR(i,1,n-m-dec) printf("%d %d\n",10000-i*(i+1)/2,1000-i);
    }
}
int main(){
    cin>>n>>m;
    solve();
}