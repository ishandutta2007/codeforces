#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,a[N<<1];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int v=*min_element(a+1,a+n+1);
    FOR(i,1,n) a[i]=a[i]>v;
    FOR(i,n+1,2*n) a[i]=a[i-n];
    int ans=0;
    for(int i=2*n,cur=0;i;i--){
        if (a[i]) cur++;
        else cur=0;
        ans=max(ans,cur);
    }
    cout<<1LL*n*v+ans;
}