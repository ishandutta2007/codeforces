#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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

int n,a[N];
ll psum[N];
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    FOR(i,1,n) psum[i]=psum[i-1]+a[i];
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
}
double cal(int p1,int t1,int len){
    ll ans1=psum[p1-1]-psum[p1-len-1]+psum[n]-psum[n-len]+a[p1];
    if (t1) ans1+=a[p1+1];
    double ans=(ans1+.0)/(len*2+1+t1);
    if (t1) ans-=(a[p1]+a[p1+1]+.0)/2;
    else ans-=a[p1];
    return ans;
}
void solve(){
    double ans=0;
    int pos=1,type=0,len=0;
    REP(i,2,n-1) if (maximize(ans,cal(i,1,1))) pos=i,type=1,len=1;
    REP(st,2,n){
        int L=1,R=min(st-1,n-st)-1;
        while (L<=R){
            int mid=(L+R)/2;
            if (cal(st,0,mid)>cal(st,0,mid+1)) R=mid-1;
            else L=mid+1;
        }
//        cout<<st<<" "<<R<<" "<<cal(st,0,st-R)<<" "<<cal(st,0,st-R+1)<<'\n';
//        cout<<st<<" "<<R<<'\n';
//        FOR(i,1,min(st-1,n-st)) cout<<cal(st,0,i)<<" ";
//        ENDL;
        if (maximize(ans,cal(st,0,L))) pos=st,type=0,len=L;
    }
    printf("%d\n%d ",len*2+type+1,a[pos]);
    FOR(i,1,len) printf("%d %d ",a[pos-i],a[n-i+1]);
    if (type) printf("%d",a[pos+1]);
}
int main(){
//    INPUT;
    prepare();
    solve();
}