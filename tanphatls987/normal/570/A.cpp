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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+5;

int n,m,a[N],h[N];
int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        FOR(i,1,n) scanf("%d",a+i);
        h[max_element(a+1,a+n+1)-a]++;
    }
    cout<<max_element(h+1,h+n+1)-h;
}