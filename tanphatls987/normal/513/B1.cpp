#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=60;

int n,a[N];
ll m;
int main(){
    cin>>n>>m;
    int ans=0;
    FOR(i,1,n) a[i]=i;
    do{
        int sum=0;
        FOR(i,1,n)
            FOR(j,i,n) {
                int cur=a[i];
                FOR(k,i,j) cur=min(cur,a[k]);
                sum+=cur;
            }
        ans=max(ans,sum);
    }while (next_permutation(a+1,a+n+1));
    FOR(i,1,n) a[i]=i;
    do{
        int sum=0;
        FOR(i,1,n)
            FOR(j,i,n){
                int cur=a[i];
                FOR(k,i,j) cur=min(cur,a[k]);
                sum+=cur;
            }
        if (sum==ans) m--;
        if (!m){
            FOR(i,1,n) printf("%d ",a[i]);
            return 0;
        }
    }while (next_permutation(a+1,a+n+1));
}