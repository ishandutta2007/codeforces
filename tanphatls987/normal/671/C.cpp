#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int n,a[N],h[N];
ii raL[N],raR[N];
set <ii> mse;
vector <ii> v[N];
void maximize(ii &a,int x){
    if (a.Y<x) a.Y=x;
    if (a.Y>a.X) swap(a.X,a.Y);
}
void minimize(ii &a,int x){
    if (a.Y>x) a.Y=x;
    if (a.Y<a.X) swap(a.X,a.Y);
}
void makerange(int L,int R,int val){
    if (L>R) return;
//    cout<<L<<" "<<R<<" "<<val<<'\n';
    v[L].push_back(ii(R,val));
}
void prepare(){
    scanf("%d",&n);
    REP(i,0,N) raL[i]=ii(n+1,n+1);
    FOR(i,1,n){
        int x;
        scanf("%d",&x);
        maximize(raR[x],i);
        minimize(raL[x],i);
    }
    REP(i,1,N)
        for(int j=i+i;j<N;j+=i) {
            maximize(raR[i],raR[j].X);
            maximize(raR[i],raR[j].Y);
            minimize(raL[i],raL[j].X);
            minimize(raL[i],raL[j].Y);
        }
//    FOR(i,1,6) cout<<i<<" "<<raL[i].X<<" "<<raL[i].Y<<" "<<raR[i].Y<<" "<<raR[i].X<<'\n';
    REP(i,1,N) if (raL[i].Y!=n+1&&raL[i].X<raL[i].Y){

        makerange(1,raR[i].Y-1,i);
        makerange(raL[i].X+1,raR[i].X-1,i);
        makerange(raL[i].Y+1,n,i);
    }
}
ll solve(){
    ll ans=0;
    ll sumval=0;
    mse.insert(ii(n+1,0));
    FOR(i,1,n){
        sumval-=mse.begin()->Y;
        if (mse.begin()->X<i)
            mse.erase(mse.begin());
        for(auto j:v[i]){
            auto cur=mse.upper_bound(j);
            auto piv=cur;
//            cout<<j.X<<" "<<j.Y<<"=>"<<piv->X<<" "<<piv->Y<<'\n';
            if (j.Y<=piv->Y) continue;
            if (piv==mse.begin()) sumval+=1LL*(j.Y-piv->Y)*(j.X-i+1);
            else {
                --cur;
                sumval+=1LL*(j.Y-piv->Y)*(j.X-cur->X);
                while (1){
//                    cout<<"Query:"<<j.X<<" "<<j.Y<<" "<<cur->X<<" "<<cur->Y<<'\n';
                    if (cur->Y>j.Y) break;
                    if (cur==mse.begin()){
                        sumval+=1LL*(j.Y-cur->Y)*(cur->X-i+1);
                        mse.erase(cur);
                        break;
                    }
                    auto old=cur;
                    --cur;
                    sumval+=1LL*(j.Y-old->Y)*(old->X-cur->X);
                    mse.erase(old);
                }
            }
            mse.insert(j);
//            cout<<i<<" "<<j.X<<" "<<j.Y<<" "<<sumval<<'\n';
        }
        ans+=sumval;
//        cout<<i<<" "<<sumval<<'\n';
//        for(auto j:mse) cout<<"[]"<<j.X<<" "<<j.Y<<'\n';
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}