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

int n,dur,costsw,costrot;
int a[N<<1];
string s;
void prepare(){
    cin>>n>>costsw>>costrot>>dur;
    cin>>s;
    REP(i,0,n) a[i]=s[i]=='h'?0:costrot;
    REP(i,n,n<<1) a[i]=a[i-n];
}
int solve(){
    ll sum=0;
    FOR(i,0,n) sum+=a[i];
    int ans=0;
    for(int en=n,st=0;en<2*n;sum+=costsw+a[++en]){
        while (st<n&&sum+1LL*costsw*(en-st)+(en-st+1)>dur) sum-=a[st++];
//        cout<<st<<" "<<en<<" "<<sum+1LL*costsw*(en-st)+(en-st+1)<<'\n';
        if (sum+1LL*costsw*(en-st)+(en-st+1)<=dur) ans=max(ans,min(en-st+1,n));
    }
    sum=0;
    REP(i,0,n) sum+=a[i];
    for(int en=2*n-1,st=n;st>=0;sum+=costsw+a[--st]){
        while (en>n&&sum+1LL*costsw*(en-st)+(en-st+1)>dur) sum-=a[en--];
//        cout<<st<<" "<<en<<" "<<sum+1LL*costsw*(en-st)+(en-st+1)<<'\n';
        if (sum+1LL*costsw*(en-st)+(en-st+1)<=dur) ans=max(ans,min(en-st+1,n));
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}