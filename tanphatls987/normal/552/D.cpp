#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=2e3+10;

int n;
ii a[N],ve[N];
bool comp(ii a,ii b){
    return a.X*b.Y<a.Y*b.X;
}
bool operator ==(ii a,ii b){
    return a.X*b.Y==a.Y*b.X;
}
ll C3(int x){
    return 1LL*x*(x-1)*(x-2)/6;
}
ll C2(int x){
    return 1LL*x*(x-1)/2;
}
ll solve(){
    ll ans=C3(n);
    FOR(st,1,n-2){
        int c2=0,top=0;
        FOR(i,st+1,n) {
            ve[++top]=ii(a[i].X-a[st].X,a[i].Y-a[st].Y);
            if (ve[top].Y<0) ve[top].X*=-1,ve[top].Y*=-1;
            if (ve[top].Y==0){
                c2++,top--;
                continue;
            }
        }
        sort(ve+1,ve+top+1,comp);
//        printf("%d\n",st);
//        FOR(i,st+1,n) printf("%d %d\n",ve[i].X,ve[i].Y);
        FOR(i,1,top){
            int j=i;
            while (j<top&&ve[j+1]==ve[i]) j++;
            ans-=C2(j-i+1);
            i=j;
        }
        ans-=C2(c2);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    cout<<solve();
}