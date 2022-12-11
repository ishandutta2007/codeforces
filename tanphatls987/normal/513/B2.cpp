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
    int L=1,R=n;
    FOR(i,1,n){
        if (m>1LL<<(n-i-1)) a[R--]=i,m-=1LL<<(n-i-1);
        else a[L++]=i;
    }
    FOR(i,1,n) printf("%d ",a[i]);
}