#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const ll INF=(ll)1e18; 
const double EPS=(ld)1e-7;

ll dp[5005][5005];

int a[5005],b[5005],c[5005],d[5005],x[5005];
int n,st,e;
bool bb;

ll f(ll p,ll open){
    int i=p;
    ll& s=dp[p][open/2];
    if(p == n+1) {
        if(open) return INF;
        else return 0;
    }
    if(open<=0 && p!=1) return INF;
    if(s!=-1) return s;
    s = INF;
    if(p == st){
       s = min(s,f(p+1,open+1)+d[i]);
       if(open) s = min(s,f(p+1,open-1)+c[i]);
    }
    else if(p==e){
       s = min(s,f(p+1,open+1)+b[i]);
       if(open) s = min(s,f(p+1,open-1)+a[i]);
    }
    else{
        s = min(s,f(p+1,open+2) + b[i] + d[i]); //open new
        if(open) s = min(s,f(p+1,open-2) + a[i] + c[i]); // close two
        if(open>1){
            if(open) s = min(s,f(p+1,open) + a[i] + d[i]); //go through
            if(open) s = min(s,f(p+1,open) + b[i] + c[i]); //go through other direction (does not matter)
        }
        else{
            //only correct direction works
            if(bb) s = min(s,f(p+1,open) + a[i] + d[i]); //go through
            else  s = min(s,f(p+1,open) + b[i] + c[i]); //go through other direction (does not matter)
        }
    }
    s += open * (x[p]-x[p-1]);
    //cout<<p<<" "<<open<<" "<<s<<" "<<(s-open*(x[p]-x[p-1]))<<endl;
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>st>>e;
    rep(i,1,n+2){
        rep(j,0,5004)dp[i][j]=-1; 
    }
    x[0]=x[1];
    bb = st<e; //go forward or backwards in special case
    rep(i,1,n+1) cin>>x[i];
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) cin>>b[i];
    rep(i,1,n+1) cin>>c[i];
    rep(i,1,n+1) cin>>d[i];
    cout<<f(1,0)<<endl;
    return 0;
}