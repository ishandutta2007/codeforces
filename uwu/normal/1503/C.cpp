#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n;
ll totc;
struct City{
    ll a, c;
    bool operator<(const City &x) const{
        return a<x.a;
    }
} src;

ll solve(vector<City> vec){
    ll reach=vec[0].a+vec[0].c, ret=0;
    for (int i=1;i<vec.size();++i){
        auto [a,c]=vec[i];
        if (a>reach) ret+=a-reach;
        reach=max(reach,a+c);
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<City> l, r, m;
    for (int i=1;i<=n;++i){
        ll a, c; cin >> a >> c;
        if (i==1) src={a,c};
        totc+=c;
        m.push_back({a,c});
        if (a<src.a||i==1) l.push_back({a,c});
        if (a>=src.a) r.push_back({a,c});
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    sort(m.begin(),m.end());
    cout << totc+min(solve(l)+solve(r),solve(m)) << '\n';
}