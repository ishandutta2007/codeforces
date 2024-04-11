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
const int N=1e2+5;

int n,a[N];
int main(){
    scanf("%d",&n);
    vector <int> ans;
    FOR(i,1,n){
        FOR(j,1,n) scanf("%d",a+j);
        if (!count(a+1,a+n+1,1)&&!count(a+1,a+n+1,3)) ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}