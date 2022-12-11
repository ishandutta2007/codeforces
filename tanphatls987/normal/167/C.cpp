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
const int N=2e5+10;

int test;
ll a,b;
int win(ll a,ll b){
    if (a>b) return win(b,a);
    if (!a) return 0;
    int cur=win(b%a,a);
    if (!cur) return 1;
    b/=a;
    if (a&1) return (b%2==0);
    return (b%(a+1)%2==0);
}
int main(){
    scanf("%d",&test);
    while (test--){
        scanf("%I64d%I64d",&a,&b);
        if (win(a,b)) printf("First\n");
        else printf("Second\n");
    }
}