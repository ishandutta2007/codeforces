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
const int N=100;

int k;
void solve(){
    if (k%2==0) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    k--;
    printf("%d %d\n",4*k+2,(2*k+1)*(k+1));
    printf("%d %d\n",4*k+1,4*k+2);
    FOR(i,1,k){
        printf("%d %d\n%d %d\n",4*k+1,i,4*k+2,2*k+i);
        FOR(j,1,k) printf("%d %d\n%d %d\n",i,k+j,2*k+i,3*k+j);
    }
    FOR(i,1,k/2) printf("%d %d\n%d %d\n",k+i,2*k-i+1,3*k+i,4*k-i+1);
}
int main(){
//OUTPUT;
    cin>>k;
    solve();
}