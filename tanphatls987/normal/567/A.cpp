#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    a[0]=a[2];a[n+1]=a[n-1];
    FOR(i,1,n) printf("%d %d\n",min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i])),max(a[i]-a[1],a[n]-a[i]));
}