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
const int N=1e5+10;

int n,b[N],a[N],p[N];
void add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
bool comp(int x,int y){
    return a[x]<a[y];
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=i;
    stable_sort(p+1,p+n+1,comp);
}
int solve(){
    int ans=0;
    FOR(i,1,n){
        add(p[i],1);
        ans+=get(i)==i;
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}