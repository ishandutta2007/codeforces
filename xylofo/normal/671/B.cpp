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
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<int> v(n);
    ll sm=0;
    rep(i,0,n)cin>>v[i],sm+=v[i];
    sort(allof(v));
    reverse(allof(v));
    ll kr = sm%n;
    ll kq = sm/n;
    ll abv=0;
    rep(i,0,n){
        if(i<kr) abv+=max(0LL,v[i]-kq-1);
        else     abv+=max(0LL,v[i]-kq);
    }
    if(abv<=k){
        if(kr==0) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    ll lr,rr;
    {
        ll l=0,r=1e9+7;
        while(l+1<r){
            ll mid = (r+l)/2;
            ll abv=0;
            rep(i,0,n){
                if(v[i]>mid) abv+=v[i]-mid;
                else break;
            }
            if(abv<=k) r=mid;
            else l=mid;
        }
        rr = r;
    }
    reverse(allof(v));
    {
        ll l=0,r=1e9+7;
        while(l+1<r){
            ll mid = (r+l)/2;
            ll abv=0;
            rep(i,0,n){
                if(v[i]<mid) abv-=v[i]-mid;
                else break;
            }
            if(abv<=k) l=mid;
            else r=mid;
        }
        lr = l;
    }
    //cout<<rr<<endl;
    //cout<<lr<<endl;
    cout<<rr-lr<<endl;
    return 0;
}