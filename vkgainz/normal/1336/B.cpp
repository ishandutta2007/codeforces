#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll square(int i,int j,int k){
    return (i-j)*1LL*(i-j)+(j-k)*1LL*(j-k)+(i-k)*1LL*(i-k);
}
ll lowest(vector<int> &x, vector<int> &y, vector<int> &z){
    auto i = x.begin();
    auto j = y.begin();
    auto k = z.begin();
    ll ret = 3e18;
    while(i!=x.end()){
        j = lower_bound(y.begin(),y.end(),(*i));
        auto l = (i+1);
        if(l==x.end()){
            while(j!=y.end()){
                k = lower_bound(z.begin(),z.end(),(*j));
                if(k==z.end()) break;
                ret = min(ret,square((*i),(*j),(*k)));
                ++j;
            }
        }
        else{
            while(j!=y.end() && (*j)<(*l)){
                k = lower_bound(z.begin(),z.end(),(*j));
                if(k==z.end()) break;
                ret = min(ret,square((*i),(*j),(*k)));
                ++j;
            }
        }
        ++i;
    }
    return ret;
}

vector<int> r;
vector<int> g;
vector<int> b;
void solve(){
    int nr,ng,nb;
    cin >> nr >> ng >> nb;
    r.clear();
    g.clear();
    b.clear();
    r.assign(nr,0);
    g.assign(ng,0);
    b.assign(nb,0);
    for(int i=0;i<nr;i++) cin >> r[i];
    for(int i=0;i<ng;i++) cin >> g[i];
    for(int i=0;i<nb;i++) cin >> b[i];
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    ll ans = min(lowest(r,g,b),lowest(r,b,g));
    ans = min(ans,lowest(b,r,g));
    ans = min(ans,lowest(b,g,r));
    ans = min(ans,lowest(g,b,r));
    ans = min(ans,lowest(g,r,b));
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}