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
const int N=5e3+10,M=1e6+10;
const int s[5]={0,1,3,6,10};

int n,k,a[N],h[M],r[M];
int solve(){
    if (k>=n-1) return 1;
    FOR(i,n-k,a[n]){
        int top=0;
        for(int j=i;j<=a[n];j+=i){
            top+=r[j];
            if (top>s[k]) break;
        }
        if (top>s[k]) continue;
        top=0;
        FOR(j,1,n){
            if (h[a[j]%i]==i) top++;
            if (top>k) break;
            h[a[j]%i]=i;
        }
        if (top<=k) return i;
    }
    return a[n]+1;
}
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    FOR(i,1,n)
        FOR(j,i+1,n) r[a[j]-a[i]]++;
    cout<<solve();
}