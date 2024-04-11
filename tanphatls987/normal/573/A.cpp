#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e5+10;

int n,a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        FOR(j,2,3) while (a[i]%j==0) a[i]/=j;
    }
    if (count(a+1,a+n+1,a[1])==n) printf("Yes");
    else printf("No");
}