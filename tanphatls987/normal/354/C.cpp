#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e6+10,M=3e5+10;

int n,k,a[M],h[N];
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    int ans=min(a[1],k);
    FOR(i,1,n) h[max(a[i]-k,0)]++,h[a[i]+1]--;
    FOR(i,1,a[n]) h[i]+=h[i-1];
    FOR(i,k+1,a[1]){
        int c=0;
        for(int j=i;j<=a[n];j+=i) c+=h[j];
        if (c==n) ans=i;
    }
    cout<<ans;
}