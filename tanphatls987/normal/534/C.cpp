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

int n,a[N];
ll V;
int main(){
    scanf("%d%I64d",&n,&V);
    ll big=0;
    FOR(i,1,n) scanf("%d",a+i),big+=a[i];
    FOR(i,1,n){
        ll cur=big-a[i],L=0,R=a[i]+1;
        if (cur<V) L=V-1-cur;
        if (a[i]+n-1>V) R=V-(n-1)+1;
        printf("%I64d ",L+a[i]-R+1);
    }
}