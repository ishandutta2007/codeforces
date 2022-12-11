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
const int N=5e5+10;

int n,a[N],h[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    a[0]=a[1];a[n+1]=a[n];
}
void solve(){
    FOR(i,1,n) h[i]=(a[i]!=a[i-1]&&a[i]!=a[i+1]);
//    FOR(i,1,n) cout<<h[i]<<" ";ENDL;
    int ans=0;
    FOR(st,1,n) if (h[st]){
        int en=st;
        while (h[en+1]) en++;
        int len=(en-st+1);
        ans=max(ans,(len+1)/2);
//        cout<<st<<" "<<en<<'\n';
        if (a[st-1]==a[en+1]) {
            FOR(i,st,en) a[i]=a[st-1];
        }else REP(i,0,len/2) a[st+i]=a[st-1],a[en-i]=a[en+1];
        st=en;
    }
    printf("%d\n",ans);
    FOR(i,1,n) printf("%d ",a[i]);
}
int main(){
    prepare();
    solve();
}