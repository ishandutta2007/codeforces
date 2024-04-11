#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=5e5+10;

int n,k,a[N];
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
}
bool checklow(int low){
    ll need=0;
    FOR(i,1,n) need+=max(0,a[i]-low);
    return need<=k;
}
bool checkhigh(int high){
    ll need=0;
    FOR(i,1,n) need+=max(0,high-a[i]);
    return need<=k;
}
int solve(){
    ll sum=0;
    FOR(i,1,n) sum+=a[i];
    int low=(sum+n-1)/n;
    int high=sum/n;
    int L=1,R=inf;
    while (low<=R){
        int mid=(low+R)/2;
        if (checklow(mid)) R=mid-1;
        else low=mid+1;
    }
    while (L<=high){
        int mid=(L+high)/2;
        if (checkhigh(mid)) L=mid+1;
        else high=mid-1;
    }
    return low-high;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}